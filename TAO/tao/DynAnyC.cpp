/* -*- C++ -*- */
// $Id$
// ======================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    DynAnyC.cpp
//
// = AUTHOR
//
// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html
//
//
// Modified by Jeff Parsons <jp4@cs.wustl.edu>
//
// ======================================================================

#include "tao/corba.h"

#if !defined (__ACE_INLINE__)
#include "DynAnyC.i"
#endif /* !defined INLINE */

CORBA_DynAny_ptr CORBA_DynAny::_duplicate (CORBA_DynAny_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();
  
  return obj;
} // end of _duplicate

CORBA_DynAny_ptr CORBA_DynAny::_narrow (CORBA::Object_ptr obj,
                                        CORBA::Environment &env)
{
  if (CORBA::is_nil (obj))
    return CORBA_DynAny::_nil ();

  if (!obj->_is_a ("IDL:/CORBA_DynAny:1.0", env))
    return CORBA_DynAny::_nil ();

  if (!obj->_is_collocated ()
      || !obj->_servant ()
      || obj->_servant ()->_downcast ("IDL:/CORBA_DynAny:1.0") == 0)
    {
      STUB_Object* stub = obj->_stubobj ();
      stub->_incr_refcnt ();
      CORBA_DynAny_ptr new_obj = new CORBA_DynAny (stub);
      return new_obj;
    } // end of if

  STUB_Object *stub = obj->_servant ()->_create_stub (env);

  if (env.exception () != 0)
    return CORBA_DynAny::_nil ();

  void* servant = obj->_servant ()->_downcast ("IDL:/CORBA_DynAny:1.0");
  return new POA_CORBA::_tao_collocated_DynAny (
    ACE_reinterpret_cast (POA_CORBA::DynAny_ptr,
                          servant),
    stub
  );
}

CORBA_DynAny_ptr CORBA_DynAny::_nil (void)
{
  return (CORBA_DynAny_ptr) NULL;
} // end of _nil

// default constructor
CORBA_DynAny::Invalid::Invalid (void)
  : CORBA_UserException (CORBA_DynAny::_tc_Invalid)
{
}

// destructor - all members are of self managing types
CORBA_DynAny::Invalid::~Invalid (void)
{
}

// copy constructor
CORBA_DynAny::Invalid::Invalid (const CORBA_DynAny::Invalid &_tao_excp)
  : CORBA_UserException (_tao_excp._type ())
{
  }

// assignment operator
CORBA_DynAny::Invalid&
CORBA_DynAny::Invalid::operator= (const CORBA_DynAny::Invalid &_tao_excp)
{
  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
CORBA_DynAny::Invalid_ptr 
CORBA_DynAny::Invalid::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:/CORBA_DynAny/Invalid:1.0", 
                       exc->_id ())) // same type
    return ACE_dynamic_cast (CORBA_DynAny::Invalid_ptr, 
                             exc);
  else
    return 0;
}


void CORBA_DynAny::Invalid::_raise ()
{
  TAO_RAISE(*this);
}

// TAO extension - the _alloc method
CORBA::Exception *CORBA_DynAny::Invalid::_alloc (void)
{
  return new CORBA_DynAny::Invalid;
}

static const CORBA::Long _oc_CORBA_DynAny_Invalid[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  24, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f44796e), 
  ACE_NTOHL (0x416e792f), 
  ACE_NTOHL (0x496e7661), 
  ACE_NTOHL (0x6c69643a), 
  ACE_NTOHL (0x312e3000),   // repository ID = 
                            // IDL:/CORBA_DynAny/Invalid:1.0
  8, 
  ACE_NTOHL (0x496e7661), 
  ACE_NTOHL (0x6c696400),   // name = Invalid
  0,                        // member count
};
static CORBA::TypeCode _tc__tc_CORBA_DynAny_Invalid (
    CORBA::tk_except, 
    sizeof (_oc_CORBA_DynAny_Invalid), 
    (char *) &_oc_CORBA_DynAny_Invalid, 
    0
  );

CORBA::TypeCode_ptr CORBA_DynAny::_tc_Invalid = 
  &_tc__tc_CORBA_DynAny_Invalid;

// default constructor
CORBA_DynAny::InvalidValue::InvalidValue (void)
  : CORBA_UserException (CORBA_DynAny::_tc_InvalidValue)
{
}

// destructor - all members are of self managing types
CORBA_DynAny::InvalidValue::~InvalidValue (void)
{
}

// copy constructor
CORBA_DynAny::InvalidValue::InvalidValue (
    const CORBA_DynAny::InvalidValue &_tao_excp
  )
  : CORBA_UserException (_tao_excp._type ())
{
}

// assignment operator
CORBA_DynAny::InvalidValue&
CORBA_DynAny::InvalidValue::operator= (
    const CORBA_DynAny::InvalidValue &_tao_excp
  )
{
  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
CORBA_DynAny::InvalidValue_ptr 
CORBA_DynAny::InvalidValue::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:/CORBA_DynAny/InvalidValue:1.0",
                       exc->_id ())) // same type
    return ACE_dynamic_cast (CORBA_DynAny::InvalidValue_ptr, 
                             exc);
  else
    return 0;
}


void CORBA_DynAny::InvalidValue::_raise ()
{
  TAO_RAISE(*this);
}

// TAO extension - the _alloc method
CORBA::Exception *CORBA_DynAny::InvalidValue::_alloc (void)
{
  return new CORBA_DynAny::InvalidValue;
}

static const CORBA::Long _oc_CORBA_DynAny_InvalidValue[] =
{
  TAO_ENCAP_BYTE_ORDER,   // byte order
  29, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f44796e), 
  ACE_NTOHL (0x416e792f), 
  ACE_NTOHL (0x496e7661), 
  ACE_NTOHL (0x6c696456),
  ACE_NTOHL (0x616c7565), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0xfdfdfd),   // repository ID = 
                          // IDL:/CORBA_DynAny/InvalidValue:1.0
  13, 
  ACE_NTOHL (0x496e7661), 
  ACE_NTOHL (0x6c696456), 
  ACE_NTOHL (0x616c7565), 
  ACE_NTOHL (0xfdfdfd),   // name = InvalidValue
  0,                      // member count
};
static CORBA::TypeCode _tc__tc_CORBA_DynAny_InvalidValue (
    CORBA::tk_except, 
    sizeof (_oc_CORBA_DynAny_InvalidValue), 
    (char *) &_oc_CORBA_DynAny_InvalidValue, 
    0
  );

CORBA::TypeCode_ptr CORBA_DynAny::_tc_InvalidValue = 
  &_tc__tc_CORBA_DynAny_InvalidValue;

// default constructor
CORBA_DynAny::TypeMismatch::TypeMismatch (void)
  : CORBA_UserException (CORBA_DynAny::_tc_TypeMismatch)
{
}

// destructor - all members are of self managing types
CORBA_DynAny::TypeMismatch::~TypeMismatch (void)
{
}

// copy constructor
CORBA_DynAny::TypeMismatch::TypeMismatch (
    const CORBA_DynAny::TypeMismatch &_tao_excp
  )
  : CORBA_UserException (_tao_excp._type ())
{
}

// assignment operator
CORBA_DynAny::TypeMismatch&
CORBA_DynAny::TypeMismatch::operator= (
    const CORBA_DynAny::TypeMismatch &_tao_excp
  )
{
  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
CORBA_DynAny::TypeMismatch_ptr 
CORBA_DynAny::TypeMismatch::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:/CORBA_DynAny/TypeMismatch:1.0", 
                       exc->_id ())) // same type
    return ACE_dynamic_cast (CORBA_DynAny::TypeMismatch_ptr, 
                             exc);
  else
    return 0;
}


void CORBA_DynAny::TypeMismatch::_raise ()
{
  TAO_RAISE(*this);
}

// TAO extension - the _alloc method
CORBA::Exception *CORBA_DynAny::TypeMismatch::_alloc (void)
{
  return new CORBA_DynAny::TypeMismatch;
}

static const CORBA::Long _oc_CORBA_DynAny_TypeMismatch[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  29, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f44796e), 
  ACE_NTOHL (0x416e792f), 
  ACE_NTOHL (0x54797065), 
  ACE_NTOHL (0x4d69736d), 
  ACE_NTOHL (0x61746368), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0xfdfdfd),     // repository ID = 
                            // IDL:/CORBA_DynAny/TypeMismatch:1.0
  13, ACE_NTOHL (0x54797065), 
  ACE_NTOHL (0x4d69736d), 
  ACE_NTOHL (0x61746368), 
  ACE_NTOHL (0xfdfdfd),     // name = TypeMismatch
  0,                        // member count
};
static CORBA::TypeCode _tc__tc_CORBA_DynAny_TypeMismatch (
    CORBA::tk_except, 
    sizeof (_oc_CORBA_DynAny_TypeMismatch), 
    (char *) &_oc_CORBA_DynAny_TypeMismatch, 
    0
  );

CORBA::TypeCode_ptr CORBA_DynAny::_tc_TypeMismatch = 
  &_tc__tc_CORBA_DynAny_TypeMismatch;

// default constructor
CORBA_DynAny::InvalidSeq::InvalidSeq (void)
  : CORBA_UserException (CORBA_DynAny::_tc_InvalidSeq)
{
}

// destructor - all members are of self managing types
CORBA_DynAny::InvalidSeq::~InvalidSeq (void)
{
}

// copy constructor
CORBA_DynAny::InvalidSeq::InvalidSeq (
    const CORBA_DynAny::InvalidSeq &_tao_excp
  )
  : CORBA_UserException (_tao_excp._type ())
{
}

// assignment operator
CORBA_DynAny::InvalidSeq&
CORBA_DynAny::InvalidSeq::operator= (
    const CORBA_DynAny::InvalidSeq &_tao_excp
  ) 
{
  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
CORBA_DynAny::InvalidSeq_ptr 
CORBA_DynAny::InvalidSeq::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:/CORBA_DynAny/InvalidSeq:1.0", 
                       exc->_id ())) // same type
    return ACE_dynamic_cast (CORBA_DynAny::InvalidSeq_ptr, 
                             exc);
  else
    return 0;
}


void CORBA_DynAny::InvalidSeq::_raise ()
{
  TAO_RAISE(*this);
}

// TAO extension - the _alloc method
CORBA::Exception *CORBA_DynAny::InvalidSeq::_alloc (void)
{
  return new CORBA_DynAny::InvalidSeq;
}

static const CORBA::Long _oc_CORBA_DynAny_InvalidSeq[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  27, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f44796e), 
  ACE_NTOHL (0x416e792f), 
  ACE_NTOHL (0x496e7661), 
  ACE_NTOHL (0x6c696453), 
  ACE_NTOHL (0x65713a31), 
  ACE_NTOHL (0x2e3000fd),   // repository ID = 
                            // IDL:/CORBA_DynAny/InvalidSeq:1.0
  11, 
  ACE_NTOHL (0x496e7661), 
  ACE_NTOHL (0x6c696453), 
  ACE_NTOHL (0x657100fd),   // name = InvalidSeq
  0,                        // member count
};
static CORBA::TypeCode _tc__tc_CORBA_DynAny_InvalidSeq (
    CORBA::tk_except, 
    sizeof (_oc_CORBA_DynAny_InvalidSeq), 
    (char *) &_oc_CORBA_DynAny_InvalidSeq, 
    0
  );

CORBA::TypeCode_ptr CORBA_DynAny::_tc_InvalidSeq = 
  &_tc__tc_CORBA_DynAny_InvalidSeq;

CORBA::TypeCode_ptr
CORBA_DynAny::type (CORBA::Environment &)
{
  return 0;
}

void
CORBA_DynAny::assign (CORBA_DynAny_ptr CORBA_Dyn_any, 
                      CORBA::Environment &env)
{
}

CORBA_DynAny_ptr
CORBA_DynAny::copy (CORBA::Environment &env)
{
  return 0;
}

void
CORBA_DynAny::destroy (CORBA::Environment &env)
{
}

void
CORBA_DynAny::from_any (const CORBA_Any& any, 
                        CORBA::Environment &env)
{
}

CORBA::Any_ptr
CORBA_DynAny::to_any (CORBA::Environment &env)
{
  return 0;
}

CORBA_DynAny_ptr
CORBA_DynAny::current_component (CORBA::Environment &env)
{
  return 0;
}

CORBA::Boolean
CORBA_DynAny::next (CORBA::Environment &)
{
  return 0;
}

CORBA::Boolean
CORBA_DynAny::seek (CORBA::Long index,
                    CORBA::Environment &)
{
  return 0;
}

void
CORBA_DynAny::rewind (CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_boolean (CORBA::Boolean value, 
                              CORBA::Environment &env)
{
}

void
CORBA_DynAny::insert_octet (CORBA::Octet value, 
                            CORBA::Environment &env)
{
}

void
CORBA_DynAny::insert_char (CORBA::Char value, 
                           CORBA::Environment &env)
{
}

void
CORBA_DynAny::insert_short (CORBA::Short value, 
                            CORBA::Environment &env)
{
}

void
CORBA_DynAny::insert_ushort (CORBA::UShort value, 
                             CORBA::Environment &env)
{
}

void
CORBA_DynAny::insert_long (CORBA::Long value, 
                           CORBA::Environment &env)
{
}

void
CORBA_DynAny::insert_ulong (CORBA::ULong value, 
                            CORBA::Environment &env)
{
}

void
CORBA_DynAny::insert_float (CORBA::Float value, 
                            CORBA::Environment &env)
{
}

void
CORBA_DynAny::insert_double (CORBA::Double value, 
                             CORBA::Environment &env)
{
}

void
CORBA_DynAny::insert_string (const char * value, 
                             CORBA::Environment &env)
{
}

void
CORBA_DynAny::insert_reference (CORBA::Object_ptr value, 
                                CORBA::Environment &env)
{
}

void
CORBA_DynAny::insert_typecode (CORBA::TypeCode_ptr value, 
                               CORBA::Environment &env)
{
}

void
CORBA_DynAny::insert_longlong (CORBA::LongLong value, 
                               CORBA::Environment &env)
{
}

void
CORBA_DynAny::insert_ulonglong (CORBA::ULongLong value, 
                                CORBA::Environment &env)
{
}

void
CORBA_DynAny::insert_wchar (CORBA::WChar value, 
                            CORBA::Environment &env)
{
}

void
CORBA_DynAny::insert_any (const CORBA::Any& value, 
                          CORBA::Environment &env)
{
}

CORBA::Boolean
CORBA_DynAny::get_boolean (CORBA::Environment &env)
{
  return 0;
}

CORBA::Octet
CORBA_DynAny::get_octet (CORBA::Environment &env)
{
  return 0;
}

CORBA::Char
CORBA_DynAny::get_char (CORBA::Environment &env)
{
  return 0;
}

CORBA::Short
CORBA_DynAny::get_short (CORBA::Environment &env)
{
  return 0;
}

CORBA::UShort
CORBA_DynAny::get_ushort (CORBA::Environment &env)
{
  return 0;
}

CORBA::Long
CORBA_DynAny::get_long (CORBA::Environment &env)
{
  return 0;
}

CORBA::ULong
CORBA_DynAny::get_ulong (CORBA::Environment &env)
{
  return 0;
}

CORBA::Float
CORBA_DynAny::get_float (CORBA::Environment &env)
{
  return 0;
}

CORBA::Double
CORBA_DynAny::get_double (CORBA::Environment &env)
{
  return 0;
}

char *
CORBA_DynAny::get_string (CORBA::Environment &env)
{
  return 0;
}

CORBA::Object_ptr
CORBA_DynAny::get_reference (CORBA::Environment &env)
{
  return 0;
}

CORBA::TypeCode_ptr
CORBA_DynAny::get_typecode (CORBA::Environment &env)
{
  return 0;
}

CORBA::LongLong
CORBA_DynAny::get_longlong (CORBA::Environment &env)
{
  return 0;
}

CORBA::ULongLong
CORBA_DynAny::get_ulonglong (CORBA::Environment &env)
{
  return 0;
}

CORBA::WChar
CORBA_DynAny::get_wchar (CORBA::Environment &env)
{
  return 0;
}

CORBA::Any_ptr
CORBA_DynAny::get_any (CORBA::Environment &env)
{
   return 0;
}

CORBA::Boolean CORBA_DynAny::_is_a (const CORBA::Char *value, 
                                    CORBA::Environment &env)
{
  if ((!ACE_OS::strcmp ((char *)value, 
                        "IDL:/CORBA_DynAny:1.0")) 
      || (!ACE_OS::strcmp ((char *)value, 
                           CORBA::_tc_Object->id (env))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, 
                                      env); // remote call
}

const char* CORBA_DynAny::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynAny:1.0";
}

static const CORBA::Long _oc_CORBA_DynAny[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  16, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f44796e), 
  ACE_NTOHL (0x416e793a), 
  ACE_NTOHL (0x312e3000),   // repository ID = IDL:/CORBA_DynAny:1.0
  7, 
  ACE_NTOHL (0x44796e41), 
  ACE_NTOHL (0x6e7900fd),   // name = CORBA_DynAny,
};
static CORBA::TypeCode _tc__tc_CORBA_DynAny (
    CORBA::tk_objref, 
    sizeof (_oc_CORBA_DynAny), 
    (char *) &_oc_CORBA_DynAny, 
    0
  );

CORBA::TypeCode_ptr _tc_CORBA_DynAny = &_tc__tc_CORBA_DynAny;

CORBA_DynEnum_ptr CORBA_DynEnum::_duplicate (CORBA_DynEnum_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();
  
  return obj;
} // end of _duplicate

CORBA_DynEnum_ptr CORBA_DynEnum::_narrow (CORBA::Object_ptr obj,
                                          CORBA::Environment &env)
{
  if (CORBA::is_nil (obj))
    return CORBA_DynEnum::_nil ();

  if (!obj->_is_a ("IDL:/CORBA_DynEnum:1.0", env))
    return CORBA_DynEnum::_nil ();

  if (!obj->_is_collocated ()
      || !obj->_servant ()
      || obj->_servant ()->_downcast ("IDL:/CORBA_DynEnum:1.0") == 0)
    {
      STUB_Object* stub = obj->_stubobj ();
      stub->_incr_refcnt ();
      CORBA_DynEnum_ptr new_obj = new CORBA_DynEnum (stub);
      return new_obj;
    } // end of if

  STUB_Object *stub = obj->_servant ()->_create_stub (env);

  if (env.exception () != 0)
    return CORBA_DynEnum::_nil ();

  void* servant = obj->_servant ()->_downcast ("IDL:/CORBA_DynEnum:1.0");
  return new POA_CORBA::_tao_collocated_DynEnum (
    ACE_reinterpret_cast (POA_CORBA::DynEnum_ptr, 
                          servant),
    stub
  );
}

CORBA_DynEnum_ptr CORBA_DynEnum::_nil (void)
{
  return (CORBA_DynEnum_ptr) NULL;
} // end of _nil

char* 
CORBA_DynEnum::value_as_string (CORBA::Environment& env)
{
  return 0;
}

void 
CORBA_DynEnum::value_as_string (const char* value_as_string,
                                CORBA::Environment& env)
{
}

CORBA::ULong 
CORBA_DynEnum::value_as_ulong (CORBA::Environment&)
{
  return 0;
}

void 
CORBA_DynEnum::value_as_ulong (CORBA::ULong value_as_ulong,
                               CORBA::Environment& env)
{
}

CORBA::Boolean CORBA_DynEnum::_is_a (const CORBA::Char *value, 
                                     CORBA::Environment &env)
{
  if ((!ACE_OS::strcmp ((char *)value, 
                        "IDL:/CORBA_DynEnum:1.0")) 
      || (!ACE_OS::strcmp ((char *)value, 
                           "IDL:/CORBA_DynAny:1.0")) 
      || (!ACE_OS::strcmp ((char *)value,
                           CORBA::_tc_Object->id (env))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, 
                                      env); // remote call
}

const char* CORBA_DynEnum::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynEnum:1.0";
}

static const CORBA::Long _oc_CORBA_DynEnum[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  17, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f44796e), 
  ACE_NTOHL (0x456e756d), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0xfdfdfd),     // repository ID = IDL:/CORBA_DynEnum:1.0
  8, 
  ACE_NTOHL (0x44796e45), 
  ACE_NTOHL (0x6e756d00),   // name = CORBA_DynEnum,
};
static CORBA::TypeCode _tc__tc_CORBA_DynEnum (CORBA::tk_objref, 
                                              sizeof (_oc_CORBA_DynEnum), 
                                              (char *) &_oc_CORBA_DynEnum, 
                                              0);

CORBA::TypeCode_ptr _tc_CORBA_DynEnum = &_tc__tc_CORBA_DynEnum;

static const CORBA::Long _oc_FieldName[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  19, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f466965), 
  ACE_NTOHL (0x6c644e61), 
  ACE_NTOHL (0x6d653a31), 
  ACE_NTOHL (0x2e3000fd),   // repository ID = IDL:/FieldName:1.0
  10, 
  ACE_NTOHL (0x4669656c), 
  ACE_NTOHL (0x644e616d), 
  ACE_NTOHL (0x6500fdfd),   // name = FieldName
  CORBA::tk_string, 
  0,                        // string length
};
static CORBA::TypeCode _tc__tc_FieldName (CORBA::tk_alias, 
                                          sizeof (_oc_FieldName), 
                                          (char *) &_oc_FieldName, 
                                          0);

CORBA::TypeCode_ptr _tc_FieldName = &_tc__tc_FieldName;

static const CORBA::Long _oc_NameValuePair[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  23, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f4e616d), 
  ACE_NTOHL (0x6556616c), 
  ACE_NTOHL (0x75655061), 
  ACE_NTOHL (0x69723a31), 
  ACE_NTOHL (0x2e3000fd),   // repository ID = IDL:/NameValuePair:1.0
  14,   
  ACE_NTOHL (0x4e616d65), 
  ACE_NTOHL (0x56616c75), 
  ACE_NTOHL (0x65506169), 
  ACE_NTOHL (0x7200fdfd),   // name = NameValuePair
  2,                        // member count
  3,
  ACE_NTOHL (0x696400fd),   // name = id
  CORBA::tk_alias,          // typecode kind for typedefs
  52,                       // encapsulation length
  TAO_ENCAP_BYTE_ORDER,     // byte order
  19, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f466965), 
  ACE_NTOHL (0x6c644e61), 
  ACE_NTOHL (0x6d653a31), 
  ACE_NTOHL (0x2e3000fd),   // repository ID = IDL:/FieldName:1.0
  10, 
  ACE_NTOHL (0x4669656c), 
  ACE_NTOHL (0x644e616d), 
  ACE_NTOHL (0x6500fdfd),   // name = FieldName
  CORBA::tk_string, 
  0,                        // string length
  6, 
  ACE_NTOHL (0x76616c75), 
  ACE_NTOHL (0x6500fdfd),   // name = value
  CORBA::tk_any,
};

static CORBA::TypeCode _tc__tc_NameValuePair (CORBA::tk_struct, 
                                              sizeof (_oc_NameValuePair), 
                                              (char *) &_oc_NameValuePair, 
                                              0);

CORBA::TypeCode_ptr _tc_NameValuePair = &_tc__tc_NameValuePair;


#if !defined (_NAMEVALUEPAIRSEQ_CS_)
#define _NAMEVALUEPAIRSEQ_CS_

// *************************************************************
// NameValuePairSeq
// *************************************************************

NameValuePairSeq::NameValuePairSeq (void)
{}
NameValuePairSeq::NameValuePairSeq (CORBA::ULong max) // uses max size
  : 
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION) \
             || !defined (TAO_LACKS_TEMPLATE_SPECIALIZATION)
  _TAO_Unbounded_Sequence_NameValuePairSeq
#else /* AHETI */
  TAO_Unbounded_Sequence<NameValuePair>
#endif /* AHETI */ 
 (max)
{}
NameValuePairSeq::NameValuePairSeq (CORBA::ULong max, 
                                    CORBA::ULong length, 
                                    NameValuePair *buffer, 
                                    CORBA::Boolean release)
  : 
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION) \
             || !defined (TAO_LACKS_TEMPLATE_SPECIALIZATION)
  _TAO_Unbounded_Sequence_NameValuePairSeq
#else /* AHETI */
  TAO_Unbounded_Sequence<NameValuePair>
#endif /* AHETI */ 
 (max, length, buffer, release)
{}
NameValuePairSeq::NameValuePairSeq (
    const NameValuePairSeq &seq
  ) // copy ctor
  : 
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION) \
             || !defined (TAO_LACKS_TEMPLATE_SPECIALIZATION)
  _TAO_Unbounded_Sequence_NameValuePairSeq
#else /* AHETI */
  TAO_Unbounded_Sequence<NameValuePair>
#endif /* AHETI */ 
 (seq)
{}
NameValuePairSeq::~NameValuePairSeq (void) // dtor
{}


#endif /* end #if !defined */

static const CORBA::Long _oc_NameValuePairSeq[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  26, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f4e616d), 
  ACE_NTOHL (0x6556616c), 
  ACE_NTOHL (0x75655061), 
  ACE_NTOHL (0x69725365), 
  ACE_NTOHL (0x713a312e), 
  ACE_NTOHL (0x3000fdfd),   // repository ID = IDL:/NameValuePairSeq:1.0
  17, 
  ACE_NTOHL (0x4e616d65), 
  ACE_NTOHL (0x56616c75), 
  ACE_NTOHL (0x65506169), 
  ACE_NTOHL (0x72536571), 
  ACE_NTOHL (0xfdfdfd),     // name = NameValuePairSeq
  CORBA::tk_sequence,       // typecode kind
  156,                      // encapsulation length
  TAO_ENCAP_BYTE_ORDER,     // byte order
  CORBA::tk_struct,         // typecode kind
  140,                      // encapsulation length
  TAO_ENCAP_BYTE_ORDER,     // byte order
  23, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f4e616d), 
  ACE_NTOHL (0x6556616c), 
  ACE_NTOHL (0x75655061), 
  ACE_NTOHL (0x69723a31), 
  ACE_NTOHL (0x2e3000fd),   // repository ID = IDL:/NameValuePair:1.0
  14, 
  ACE_NTOHL (0x4e616d65), 
  ACE_NTOHL (0x56616c75), 
  ACE_NTOHL (0x65506169), 
  ACE_NTOHL (0x7200fdfd),   // name = NameValuePair
  2,                        // member count
  3, 
  ACE_NTOHL (0x696400fd),   // name = id
  CORBA::tk_alias,          // typecode kind for typedefs
  52,                       // encapsulation length
  TAO_ENCAP_BYTE_ORDER,     // byte order
  19, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f466965), 
  ACE_NTOHL (0x6c644e61), 
  ACE_NTOHL (0x6d653a31), 
  ACE_NTOHL (0x2e3000fd),   // repository ID = IDL:/FieldName:1.0
  10, 
  ACE_NTOHL (0x4669656c), 
  ACE_NTOHL (0x644e616d), 
  ACE_NTOHL (0x6500fdfd),   // name = FieldName
  CORBA::tk_string, 
  0,                        // string length
  6, 
  ACE_NTOHL (0x76616c75), 
  ACE_NTOHL (0x6500fdfd),   // name = value
  CORBA::tk_any,
  0,
};

static CORBA::TypeCode _tc__tc_NameValuePairSeq (
    CORBA::tk_alias, 
    sizeof (_oc_NameValuePairSeq), 
    (char *) &_oc_NameValuePairSeq, 
    0
  );

CORBA::TypeCode_ptr _tc_NameValuePairSeq = &_tc__tc_NameValuePairSeq;

CORBA_DynStruct_ptr CORBA_DynStruct::_duplicate (CORBA_DynStruct_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();
  
  return obj;
} // end of _duplicate

CORBA_DynStruct_ptr CORBA_DynStruct::_narrow (CORBA::Object_ptr obj,
                                              CORBA::Environment &env)
{
  if (CORBA::is_nil (obj))
    return CORBA_DynStruct::_nil ();

  if (!obj->_is_a ("IDL:/CORBA_DynStruct:1.0", env))
    return CORBA_DynStruct::_nil ();

  if (!obj->_is_collocated ()
      || !obj->_servant ()
      || obj->_servant ()->_downcast ("IDL:/CORBA_DynStruct:1.0") == 0
      )
    {
      STUB_Object* stub = obj->_stubobj ();
      stub->_incr_refcnt ();
      CORBA_DynStruct_ptr new_obj = new CORBA_DynStruct (stub);
      return new_obj;
    } // end of if

  STUB_Object *stub = obj->_servant ()->_create_stub (env);

  if (env.exception () != 0)
    return CORBA_DynStruct::_nil ();

  void* servant = obj->_servant ()->_downcast ("IDL:/CORBA_DynStruct:1.0");
  return new POA_CORBA::_tao_collocated_DynStruct (
    ACE_reinterpret_cast (POA_CORBA::DynStruct_ptr, 
                          servant),
    stub
  );
}

CORBA_DynStruct_ptr CORBA_DynStruct::_nil (void)
{
  return (CORBA_DynStruct_ptr) NULL;
} // end of _nil

FieldName
CORBA_DynStruct::current_member_name (CORBA::Environment& env)
{
  return 0;
}

CORBA::TCKind
CORBA_DynStruct::current_member_kind (CORBA::Environment& env)
{
  return CORBA::tk_null;
}

NameValuePairSeq* 
CORBA_DynStruct::get_members (CORBA::Environment& env)
{
  return 0;
}

void 
CORBA_DynStruct::set_members (const NameValuePairSeq& value,
                              CORBA::Environment& env)
{
}

CORBA::Boolean CORBA_DynStruct::_is_a (const CORBA::Char *value, 
                                       CORBA::Environment &env)
{
  if ((!ACE_OS::strcmp ((char *)value, 
                        "IDL:/CORBA_DynStruct:1.0")) 
      || (!ACE_OS::strcmp ((char *)value, 
                           "IDL:/CORBA_DynAny:1.0")) 
      || (!ACE_OS::strcmp ((char *)value, 
                           CORBA::_tc_Object->id (env))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, 
                                      env); // remote call
}

const char* CORBA_DynStruct::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynStruct:1.0";
}

static const CORBA::Long _oc_CORBA_DynStruct[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  19, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f44796e), 
  ACE_NTOHL (0x53747275), 
  ACE_NTOHL (0x63743a31), 
  ACE_NTOHL (0x2e3000fd),   // repository ID = IDL:/CORBA_DynStruct:1.0
  10, 
  ACE_NTOHL (0x44796e53), 
  ACE_NTOHL (0x74727563), 
  ACE_NTOHL (0x7400fdfd),   // name = CORBA_DynStruct,
};

static CORBA::TypeCode _tc__tc_CORBA_DynStruct (
    CORBA::tk_objref, 
    sizeof (_oc_CORBA_DynStruct), 
    (char *) &_oc_CORBA_DynStruct, 
    0
  );

CORBA::TypeCode_ptr _tc_CORBA_DynStruct = &_tc__tc_CORBA_DynStruct;

CORBA_DynUnion_ptr CORBA_DynUnion::_duplicate (CORBA_DynUnion_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();
  
  return obj;
} // end of _duplicate

CORBA_DynUnion_ptr CORBA_DynUnion::_narrow (CORBA::Object_ptr obj,
                                            CORBA::Environment &env)
{
  if (CORBA::is_nil (obj))
    return CORBA_DynUnion::_nil ();

  if (!obj->_is_a ("IDL:/CORBA_DynUnion:1.0", 
                   env))
    return CORBA_DynUnion::_nil ();

  if (!obj->_is_collocated ()
      || !obj->_servant ()
      || obj->_servant ()->_downcast ("IDL:/CORBA_DynUnion:1.0") == 0)
    {
      STUB_Object* stub = obj->_stubobj ();
      stub->_incr_refcnt ();
      CORBA_DynUnion_ptr new_obj = new CORBA_DynUnion (stub);
      return new_obj;
    } // end of if

  STUB_Object *stub = obj->_servant ()->_create_stub (env);

  if (env.exception () != 0)
    return CORBA_DynUnion::_nil ();

  void* servant = obj->_servant ()->_downcast ("IDL:/CORBA_DynUnion:1.0");
  return new POA_CORBA::_tao_collocated_DynUnion (
    ACE_reinterpret_cast (POA_CORBA::DynUnion_ptr, 
                          servant),
    stub
  );
}

CORBA_DynUnion_ptr CORBA_DynUnion::_nil (void)
{
  return (CORBA_DynUnion_ptr) NULL;
} // end of _nil

CORBA::Boolean 
CORBA_DynUnion::set_as_default (CORBA::Environment& env)
{
  return 0;
}

void
CORBA_DynUnion::set_as_default (CORBA::Boolean set_as_default,
                                CORBA::Environment&)
{
}

CORBA_DynAny_ptr 
CORBA_DynUnion::discriminator (CORBA::Environment& env)
{
  return 0;
}

CORBA::TCKind 
CORBA_DynUnion::discriminator_kind (CORBA::Environment& env)
{
  return CORBA::tk_null;
}

CORBA_DynAny_ptr 
CORBA_DynUnion::member (CORBA::Environment& env)
{
  return 0;
}

char* 
CORBA_DynUnion::member_name (CORBA::Environment& env)
{
  return 0;
}

void 
CORBA_DynUnion::member_name (const char* member_name,
                             CORBA::Environment& env)
{
}


CORBA::TCKind 
CORBA_DynUnion::member_kind (CORBA::Environment& env)
{
  return CORBA::tk_null;
}

CORBA::Boolean CORBA_DynUnion::_is_a (const CORBA::Char *value, 
                                      CORBA::Environment &env)
{
  if ((!ACE_OS::strcmp ((char *)value, 
                        "IDL:/CORBA_DynUnion:1.0")) 
      || (!ACE_OS::strcmp ((char *)value, 
                           "IDL:/CORBA_DynAny:1.0")) 
      || (!ACE_OS::strcmp ((char *)value, 
                           CORBA::_tc_Object->id (env))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, 
                                      env); // remote call
}

const char* CORBA_DynUnion::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynUnion:1.0";
}

static const CORBA::Long _oc_CORBA_DynUnion[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  18, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f44796e), 
  ACE_NTOHL (0x556e696f), 
  ACE_NTOHL (0x6e3a312e), 
  ACE_NTOHL (0x3000fdfd),   // repository ID = IDL:/CORBA_DynUnion:1.0
  9, 
  ACE_NTOHL (0x44796e55), 
  ACE_NTOHL (0x6e696f6e), 
  ACE_NTOHL (0xfdfdfd),     // name = CORBA_DynUnion,
};

static CORBA::TypeCode _tc__tc_CORBA_DynUnion (
    CORBA::tk_objref, 
    sizeof (_oc_CORBA_DynUnion), 
    (char *) &_oc_CORBA_DynUnion, 
    0
  );

CORBA::TypeCode_ptr _tc_CORBA_DynUnion = &_tc__tc_CORBA_DynUnion;


#if !defined (_ANYSEQ_CS_)
#define _ANYSEQ_CS_

// *************************************************************
// AnySeq
// *************************************************************

AnySeq::AnySeq (void)
{}
AnySeq::AnySeq (CORBA::ULong max) // uses max size
  : 
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION) \
       || !defined (TAO_LACKS_TEMPLATE_SPECIALIZATION)
  _TAO_Unbounded_Sequence_AnySeq
#else /* AHETI */
  TAO_Unbounded_Sequence<CORBA::Any>
#endif /* AHETI */ 
 (max)
{}
AnySeq::AnySeq (CORBA::ULong max, 
                CORBA::ULong length, 
                CORBA::Any *buffer, 
                CORBA::Boolean release)
  : 
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION) \
             || !defined (TAO_LACKS_TEMPLATE_SPECIALIZATION)
  _TAO_Unbounded_Sequence_AnySeq
#else /* AHETI */
  TAO_Unbounded_Sequence<CORBA::Any>
#endif /* AHETI */ 
 (max, length, buffer, release)
{}
AnySeq::AnySeq (const AnySeq &seq) // copy ctor
  : 
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION) \
             || !defined (TAO_LACKS_TEMPLATE_SPECIALIZATION)
  _TAO_Unbounded_Sequence_AnySeq
#else /* AHETI */
  TAO_Unbounded_Sequence<CORBA::Any>
#endif /* AHETI */ 
 (seq)
{}
AnySeq::~AnySeq (void) // dtor
{}


#endif /* end #if !defined */

static const CORBA::Long _oc_AnySeq[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  16, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f416e79), 
  ACE_NTOHL (0x5365713a), 
  ACE_NTOHL (0x312e3000),   // repository ID = IDL:/AnySeq:1.0
  7, 
  ACE_NTOHL (0x416e7953), 
  ACE_NTOHL (0x657100fd),   // name = AnySeq
  CORBA::tk_sequence,       // typecode kind
  12,                       // encapsulation length
  TAO_ENCAP_BYTE_ORDER,     // byte order
  CORBA::tk_any,
  0,
};

static CORBA::TypeCode _tc__tc_AnySeq (CORBA::tk_alias, 
                                       sizeof (_oc_AnySeq), 
                                       (char *) &_oc_AnySeq, 
                                       0);

CORBA::TypeCode_ptr _tc_AnySeq = &_tc__tc_AnySeq;

CORBA_DynSequence_ptr CORBA_DynSequence::_duplicate (
    CORBA_DynSequence_ptr obj
  )
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();
  
  return obj;
} // end of _duplicate

CORBA_DynSequence_ptr CORBA_DynSequence::_narrow (CORBA::Object_ptr obj,
                                                  CORBA::Environment &env)
{
  if (CORBA::is_nil (obj))
    return CORBA_DynSequence::_nil ();

  if (!obj->_is_a ("IDL:/CORBA_DynSequence:1.0", 
                   env))
    return CORBA_DynSequence::_nil ();

  if (!obj->_is_collocated ()
      || !obj->_servant ()
      || obj->_servant ()->_downcast ("IDL:/CORBA_DynSequence:1.0") == 0)
    {
      STUB_Object* stub = obj->_stubobj ();
      stub->_incr_refcnt ();
      CORBA_DynSequence_ptr new_obj = new CORBA_DynSequence (stub);
      return new_obj;
    } // end of if
  STUB_Object *stub = obj->_servant ()->_create_stub (env);

  if (env.exception () != 0)
    return CORBA_DynSequence::_nil ();  

  void* servant = obj->_servant ()->_downcast ("IDL:/CORBA_DynSequence:1.0");
  return new POA_CORBA::_tao_collocated_DynSequence (
    ACE_reinterpret_cast (POA_CORBA::DynSequence_ptr, 
                          servant),
    stub
  );
}

CORBA_DynSequence_ptr CORBA_DynSequence::_nil (void)
{
  return (CORBA_DynSequence_ptr)NULL;
} // end of _nil

CORBA::ULong 
CORBA_DynSequence::length (CORBA::Environment &)
{
  return 0;
}

void 
CORBA_DynSequence::length (CORBA::ULong length,
                           CORBA::Environment& env)
{
}

AnySeq_ptr 
CORBA_DynSequence::get_elements (CORBA::Environment& env)
{
  return 0;
}

void 
CORBA_DynSequence::set_elements (const AnySeq& value,
                                 CORBA::Environment& env)
{
}

CORBA::Boolean CORBA_DynSequence::_is_a (const CORBA::Char *value, 
                                         CORBA::Environment &env)
{
  if((!ACE_OS::strcmp ((char *)value, 
                       "IDL:/CORBA_DynSequence:1.0")) 
     || (!ACE_OS::strcmp ((char *) value, 
                          "IDL:/CORBA_DynAny:1.0")) 
     || (!ACE_OS::strcmp ((char *) value, 
                          CORBA::_tc_Object->id (env))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, 
                                      env); // remote call
}

const char* CORBA_DynSequence::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynSequence:1.0";
}

static const CORBA::Long _oc_CORBA_DynSequence[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  21, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f44796e), 
  ACE_NTOHL (0x53657175), 
  ACE_NTOHL (0x656e6365), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0xfdfdfd),     // repository ID = IDL:/CORBA_DynSequence:1.0
  12, 
  ACE_NTOHL (0x44796e53), 
  ACE_NTOHL (0x65717565), 
  ACE_NTOHL (0x6e636500),  // name = CORBA_DynSequence,
};

static CORBA::TypeCode _tc__tc_CORBA_DynSequence (
    CORBA::tk_objref, 
    sizeof (_oc_CORBA_DynSequence), 
    (char *) &_oc_CORBA_DynSequence, 
    0
  );

CORBA::TypeCode_ptr _tc_CORBA_DynSequence = 
  &_tc__tc_CORBA_DynSequence;

CORBA_DynArray_ptr CORBA_DynArray::_duplicate (CORBA_DynArray_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();
  
  return obj;
} // end of _duplicate

CORBA_DynArray_ptr CORBA_DynArray::_narrow (CORBA::Object_ptr obj,
                                            CORBA::Environment &env)
{
  if (CORBA::is_nil (obj))
    return CORBA_DynArray::_nil ();

  if (!obj->_is_a ("IDL:/CORBA_DynArray:1.0", 
                   env))
    return CORBA_DynArray::_nil ();

  if (!obj->_is_collocated ()
      || !obj->_servant ()
      || obj->_servant ()->_downcast ("IDL:/CORBA_DynArray:1.0") == 0)
    {
      STUB_Object* stub = obj->_stubobj ();
      stub->_incr_refcnt ();
      CORBA_DynArray_ptr new_obj = new CORBA_DynArray (stub);
      return new_obj;
    } // end of if

  STUB_Object *stub = obj->_servant ()->_create_stub (env);

  if (env.exception () != 0)
    return CORBA_DynArray::_nil ();

  void* servant = obj->_servant ()->_downcast ("IDL:/CORBA_DynArray:1.0");
  return new POA_CORBA::_tao_collocated_DynArray (
    ACE_reinterpret_cast (POA_CORBA::DynArray_ptr, 
                          servant),
    stub
  );
}

CORBA_DynArray_ptr CORBA_DynArray::_nil (void)
{
  return (CORBA_DynArray_ptr) NULL;
} // end of _nil

AnySeq_ptr 
CORBA_DynArray::get_elements (CORBA::Environment& env)
{
  return 0;
}

void 
CORBA_DynArray::set_elements (const AnySeq& value,
                              CORBA::Environment& env)
{
}

CORBA::Boolean CORBA_DynArray::_is_a (const CORBA::Char *value, 
                                      CORBA::Environment &env)
{
  if ((!ACE_OS::strcmp ((char *)value, 
                        "IDL:/CORBA_DynArray:1.0")) 
      || (!ACE_OS::strcmp ((char *)value, 
                           "IDL:/CORBA_DynAny:1.0")) 
      || (!ACE_OS::strcmp ((char *)value, 
                           CORBA::_tc_Object->id (env))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, env); // remote call
}

const char* CORBA_DynArray::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynArray:1.0";
}

static const CORBA::Long _oc_CORBA_DynArray[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  18, 
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x2f44796e), 
  ACE_NTOHL (0x41727261), 
  ACE_NTOHL (0x793a312e), 
  ACE_NTOHL (0x3000fdfd),   // repository ID = IDL:/CORBA_DynArray:1.0
  9, 
  ACE_NTOHL (0x44796e41), 
  ACE_NTOHL (0x72726179), 
  ACE_NTOHL (0xfdfdfd),     // name = CORBA_DynArray,
};

static CORBA::TypeCode _tc__tc_CORBA_DynArray (
    CORBA::tk_objref, 
    sizeof (_oc_CORBA_DynArray), 
    (char *) &_oc_CORBA_DynArray, 
    0
  );

CORBA::TypeCode_ptr _tc_CORBA_DynArray = 
    &_tc__tc_CORBA_DynArray;

