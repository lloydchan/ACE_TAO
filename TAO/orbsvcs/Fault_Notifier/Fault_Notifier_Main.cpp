/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    FaultNotifierMain.cpp
 *
 *  $Id$
 *
 *  This file is part of Fault Tolerant CORBA.
 *  This file provides the main routine for a process that
 *  implements the FaultNotifier interface and manages
 *  a set of FaultNotifiers.
 *
 *  @author Dale Wilson <wilson_d@ociweb.com>
 */
//=============================================================================

#include "FT_Notifier_i.h"

#include "ace/Argv_Type_Converter.h"
#include "tao/PortableServer/ORB_Manager.h"

int ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  int result = 0;
  // Copy command line parameter.
  // and hide it's unicodeness.
  ACE_Argv_Type_Converter command_line(argc, argv);

  char ** asciiArgv = command_line.get_ASCII_argv();

  ACE_TRY_NEW_ENV
  {
    // Create an object that manages all the
    // details of being a server.
    TAO_ORB_Manager orbManager;
    result = orbManager.init (argc, asciiArgv
        ACE_ENV_ARG_PARAMETER);
    if(result == 0)
    {
      ACE_CHECK_RETURN (-1);

      // create an instance of the notifier and let it
      // see the arguments.
      FT_FaultNotifier_i notifier;
      result = notifier.parse_args (argc, asciiArgv);
      if (result == 0)
      {
        //////////////////////////////////
        // let the notifier register itself
        ACE_ERROR ((LM_ERROR,
          "%n\n%T: Fault Notifier: Registering\n"
          ));

        result = notifier.self_register(orbManager);
        if (result == 0)
        {
          ACE_ERROR ((LM_ERROR,
            "%n\n%T: Fault Notifier Ready %s\n", notifier.identity()
            ));

          //////////////////////////////////
          // Run the main event loop for the ORB.
//          result = orbManager.run (ACE_ENV_SINGLE_ARG_PARAMETER);
          // Initial run to initialize the orb
          ACE_Time_Value tv(1,0);
          result = orbManager.run (tv
            ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;
          // now run event loop
          CORBA::ORB_var orb = orbManager.orb();
          int quit = 0;
          while (result == 0 && ! quit )
          {
            ACE_Time_Value work_tv(1,0);
            orb->perform_work(work_tv
              ACE_ENV_ARG_PARAMETER);
            ACE_TRY_CHECK;
            quit = notifier.idle(result);
          }
          notifier.self_unregister(ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          ACE_ERROR ((LM_ERROR,
            "%n\n%T: Fault Notifier Terminated. %s\n", notifier.identity()
            ));
        }
        else
        {
          ACE_ERROR ((LM_ERROR,
            "%n\n%T: Fault Notifier registration failed: %p\n"
            ));
          result = -1;
        }
      }
      else
      {
        // error found parsing arguments
        // we've already complained and set return != 0...
      }
    }
    else
    {
      ACE_ERROR ((LM_ERROR,
        "%n\n%T: Fault Notifier ORB manager init failed\n"
      ));
      result = -1;
    }
  }
  ACE_CATCHANY
  {
    ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
      "Fault Notifier::main\t\n");
    result = -1;
  }
  ACE_ENDTRY;
  return result;
}

