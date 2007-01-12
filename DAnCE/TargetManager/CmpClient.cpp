// $Id$
/**
 * @file CmpClient.cpp
 *
 * @brief This file contains a client of TargetManager.
 *
 * It picks up the TM ior from the Targetmanager.ior file
 * present in the current directory, and makes the calls on the
 * TM to getAllResources and getAvailable resources
 */

#include "ciao/Deployment_DataC.h"
#include "DAnCE/TargetManager/TargetManagerImplC.h"
#include "ace/streams.h"
#include "ace/FILE_IO.h"
#include "ace/FILE_Connector.h"
#include "ace/FILE_Addr.h"
#include "ace/Get_Opt.h"
#include "Config_Handlers/DnC_Dump.h"

namespace TM_Tester
{
  void write_to_file (::Deployment::Domain domain);

  const char * stringified_TM_IOR;
  bool add_to_domain = true;
  bool call_update = false;
  const char * host_name;
  
    
  bool parse_args (int argc, char *argv[])
  {
    ACE_DEBUG ((LM_DEBUG, "The Parse Agr is called\n"));
    ACE_Get_Opt get_opts (argc, argv, "t:u:d");
    int c;
    while ((c = get_opts ()) != -1)
      switch (c)
      {
        case 't':
          stringified_TM_IOR = get_opts.opt_arg ();
          ACE_DEBUG ((LM_DEBUG, "The stringified IOR is [%s]\n",stringified_TM_IOR));
          break;
        case 'u':
          host_name = get_opts.opt_arg ();
          call_update = true;
          break;
        case 'd':
         add_to_domain = false;
          break;
        case '?':  // display help for use of the server.
        default:
          ACE_ERROR_RETURN ((LM_ERROR,
                "usage:  %s\n"
                "-t <TM_IOR>\n"
                "-u <host_name in update>\n"
                "-n <delete , default add>\n"
                "\n",
                argv [0]),
              false);
      }

    return true;
  }
}

  int main (int argc, char* argv[])
  {
    try {
      // First initialize the ORB, that will remove some arguments...
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv,
            "" /* the ORB name, it can be anything! */);

      if (!TM_Tester::parse_args (argc, argv))
        return -1;
     
      // Use the first argument to create the factory object reference,
      // in real applications we use the naming service, but let's do
      // the easy part first!
      CORBA::Object_var factory_object =
        orb->string_to_object (TM_Tester::stringified_TM_IOR);

      // Now downcast the object reference to the appropriate type
      CIAO::TargetManagerImpl_var targetCmp =
        CIAO::TargetManagerImpl::_narrow (factory_object.in ());

      // Now get the facet reference from the target Manager Component
      ACE_DEBUG((LM_DEBUG, "Making a Call to provide_targetMgr ()\n"));
      Deployment::TargetManager_ptr targetI = targetCmp->provide_targetMgr ();

      // Now make calls on the Target Manager facet

      try
      {
        Deployment::Domain_var domainV = targetI->getAllResources ();
        ACE_DEBUG ((LM_DEBUG , "\n\nGetAllResources Returned \n"));
        ::Deployment::DnC_Dump::dump (domainV);
      }
      catch(CORBA::NO_IMPLEMENT &)
      {
        ACE_DEBUG((LM_DEBUG ,"Error:TargetManager:CORBA::NO_IMPLEMENT thrown\n"));
      }
      catch(CORBA::Exception &)
      {
        ACE_DEBUG((LM_DEBUG ,"Error:TargetManager:CORBA Generic Exception \n"));
        ACE_DEBUG((LM_DEBUG ,"Error:TargetManager:Exception in TargetManager call\n"));
      }


      // make a call to the commit resources .....

      bool resource_available = true;

      ::Deployment::ResourceAllocations resource_seq;

      resource_seq.length (1);

      resource_seq[0].elementName = CORBA::string_dup ("TargetManagerNode_1");

      resource_seq[0].resourceName = CORBA::string_dup ("Processor");

      resource_seq[0].property.length (1);
      resource_seq[0].property[0].name =
        CORBA::string_dup ("LoadAverage");

      CORBA::Long d = 20;
      resource_seq[0].property[0].value <<= d;

      ::Deployment::ResourceCommitmentManager_ptr manager;

      try
      {
        manager = targetI->createResourceCommitment (resource_seq);

        manager->commitResources (resource_seq);

        ACE_DEBUG ((LM_DEBUG , "\n\ncommitResources Returned \n"));
      }
      catch(CORBA::NO_IMPLEMENT &)
      {
        ACE_DEBUG ((LM_DEBUG, "Error:TargetManager:CORBA::NO_IMPLEMENT thrown\n"));
      }
      catch (::Deployment::ResourceCommitmentFailure& e)
      {
        resource_available = 0;
        ACE_DEBUG ((LM_DEBUG, "TargetManager commitResources ResourceCommitmentFailure Exception\n"));

        ACE_DEBUG ((LM_DEBUG ,
              "ResourceCommitmentFailure\n reason=[%s]\n elementName=[%s]\n resourceName=[%s]\n propertyName=[%s]\n",
              e.reason.in (),
              resource_seq[e.index].elementName.in (),
              resource_seq[e.index].resourceName.in (),
              e.propertyName.in ()));
      }
      catch(CORBA::Exception & ex)
      {
        ACE_DEBUG ((LM_DEBUG, "Error:TargetManager:commitResources Exception\n"));
        ACE_DEBUG ((LM_DEBUG, "Error:TargetManager:CORBA Generic Exception\n"));
        ACE_DEBUG ((LM_DEBUG, "Error:TargetManager:Exception in TargetManager call"));
      }



      // Make a call to release resources , if resource < 0
      try
      {
        {
          d = 10;
          resource_seq[0].property[0].value <<= d;
          manager->releaseResources (resource_seq);
          //            targetI->destroyResourceCommitment (manager);
          ACE_DEBUG ((LM_DEBUG , "\n\nreleaseResources Returned \n"));
        }
      }
      catch(CORBA::NO_IMPLEMENT &)
      {
        ACE_DEBUG ((LM_DEBUG, "Error:TargetManager:CORBA::NO_IMPLEMENT thrown\n"));
      }
      catch (Deployment::ResourceNotAvailable &)
      {
        ACE_DEBUG ((LM_DEBUG, "Error:TargetManager releaseResources ResourceNotAvailable Exception\n"));
      }
      catch(CORBA::Exception & ex)
      {
        ACE_DEBUG ((LM_DEBUG, "Error:TargetManager:releaseResources Exception\n"));
        ACE_DEBUG ((LM_DEBUG, "Error:TargetManager:CORBA Generic Exception\n"));
        ACE_DEBUG ((LM_DEBUG, "Error:TargetManager:Exception in TargetManager call"));
      }

      // Here make a call on the TM with update domain and node deletion

      ::Deployment::Domain updated;
      updated.node.length (1);
      updated.node[0].name = CORBA::string_dup (TM_Tester::host_name);

      ::CORBA::StringSeq elements;
      elements.length (0);


      if (TM_Tester::call_update)
      {
        if (TM_Tester::add_to_domain)
        {
          try
          {
            targetI->updateDomain (elements , updated, ::Deployment::Add);
          }
          catch(CORBA::NO_IMPLEMENT &)
          {
            ACE_DEBUG ((LM_DEBUG, "Error:TargetManager:CORBA::NO_IMPLEMENT thrown\n"));
          }
          catch(CORBA::Exception & ex)
          {
            ACE_DEBUG ((LM_DEBUG, "Error:TargetManager:CORBA Generic Exception\n"));
            ACE_DEBUG ((LM_DEBUG, "Error:TargetManager:Exception in UpdateDomain call"));
          }
        }
        else
        {
          try
          {
            targetI->updateDomain (elements , updated, ::Deployment::Delete);
          }
          catch(CORBA::NO_IMPLEMENT &)
          {
            ACE_DEBUG ((LM_DEBUG, "Error:TargetManager:CORBA::NO_IMPLEMENT thrown\n"));
          }
          catch(CORBA::Exception & ex)
          {
            ACE_DEBUG ((LM_DEBUG, "Error:TargetManager:CORBA Generic Exception\n"));
            ACE_DEBUG ((LM_DEBUG, "Error:TargetManager:Exception in UpdateDomain call"));
          }
        }
      }

      // Now make a call of getAvailableResources on the TargetManager ...
      try
      {
        Deployment::Domain_var domainV = targetI->getAvailableResources();

        // here write things to file ...
        TM_Tester::write_to_file (domainV.in());

        ACE_DEBUG ((LM_DEBUG , "\n\nGetAvailableResources Returned \n"));
        ::Deployment::DnC_Dump::dump (domainV);
      }
      catch(CORBA::NO_IMPLEMENT &)
      {
        ACE_DEBUG ((LM_DEBUG, "Error:TargetManager:CORBA::NO_IMPLEMENT thrown\n"));
      }
      catch(CORBA::Exception & ex)
      {
        ACE_DEBUG ((LM_DEBUG ,"Error:TargetManager:CORBA Generic Exception\n"));
        ACE_DEBUG ((LM_DEBUG,  "Error:TargetManager:Exception in TargetManager call\n"));
      }

      // Finally destroy the ORB
      orb->destroy ();
    }
    catch (CORBA::Exception & ex) 
    {
      ACE_DEBUG ((LM_DEBUG,  "Error:TargetManager:CORBA exception raised!\n"));
    }
    return 0;
  }

namespace TM_Tester
{
  void write_to_file (::Deployment::Domain domain)
  {
    for (size_t i = 0;i < domain.node.length ();i++)
    {
      std::ofstream out (domain.node[i].name.in ());


      // write in the node usage ...
      for (size_t j = 0;j < domain.node[i].resource.length ();j++)
      {

        if (!strcmp (domain.node[i].resource[j].name.in (), "Processor"))
        {
          CORBA::Double node_cpu;
          domain.node[i].resource[j].property[0].value >>= node_cpu;
          out << node_cpu << std::endl;
        }
        if (!strcmp (domain.node[i].resource[j].name.in (), "NA_Monitor"))
        {
          std::string file_name = "NA_";
          file_name += domain.node[i].name.in ();
          ACE_FILE_IO file_io;
          ACE_FILE_Connector (file_io, ACE_FILE_Addr (file_name.c_str ()));
 //         std::ofstream na_out (file_name.c_str ());
          CORBA::Double na_node_cpu;
          domain.node[i].resource[j].property[0].value >>= na_node_cpu;
          char buf[BUFSIZ];
          memset (buf , 0 , BUFSIZ);
          ACE_OS::sprintf (buf , "%f", na_node_cpu);
          file_io.send (buf, ACE_OS::strlen (buf));
//          na_out << na_node_cpu << std::endl;
//          na_out.close ();
        }
      }

      out.close ();
    }

  }
}
