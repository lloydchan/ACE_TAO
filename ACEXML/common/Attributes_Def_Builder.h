// -*- C++ -*-

//=============================================================================
/**
 *  @file    Attributes_Def_Builder.h
 *
 *  $Id$
 *
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================
#ifndef _ACEXML_ATTRIBUTES_DEF_BUILDER_H_
#define _ACEXML_ATTRIBUTES_DEF_BUILDER_H_

#include "common/XML_Types.h"
#include "common/Env.h"
#include "ace/Auto_Ptr.h"

/**
 * @ class ACEXML_Attribute_Def_Builder Attributes_Def_Builder.h "common/Attributes_Def_Builder.h"
 *
 * @ brief An abstract virtual class defining an interface
 *         for building an attribute definition from DTD.
 *
 * This class should be invisible to application programmers and
 * is only used for validator implementors.
 */
class ACEXML_Export ACEXML_Attribute_Def_Builder
{
public:

  typedef auto_ptr<ACEXML_Attribute_Def_Builder> VAR;

  typedef enum {
    CDATA,
    ID,
    IDREF,
    IDREFS,
    ENTITY,
    ENTITIES,
    NMTOKEN,
    NMTOKENS,
    NOTATION,
    ENUMERATION,
    ERROR_TYPE
  } ATT_TYPE;

  typedef enum {
    REQUIRED,
    IMPLIED,
    FIXED,
    INVALID
  } DEFAULT_DECL;

  virtual ~ACEXML_Attribute_Def_Builder () = 0;

  /**
   * Specify the name of the attribute.
   */
  virtual int setName (const ACEXML_Char *n) = 0;

  /**
   * Get the name of the attribute.
   */
  virtual const ACEXML_Char *getName (void) = 0;

  /**
   * Set the attribute type.
   */
  virtual int setAttType (const ATT_TYPE type,
                          ACEXML_Env &xmlenv)
    // ACE_THORW_SPEC ((ACEXML_SAXException))
    = 0;

  /**
   * Insert an element for NOTATION or ENUMERATION type attribute.
   */
  virtual int insertList (const ACEXML_Char *Name,
                          ACEXML_Env &xmlenv)
    // ACE_THORW_SPEC ((ACEXML_SAXException))
    = 0;

  /**
   * Set default attribute declaration.
   */
  virtual int setDefault (const DEFAULT_DECL def,
                          const ACEXML_Char *value,
                          ACEXML_Env &xmlenv)
    // ACE_THORW_SPEC ((ACEXML_SAXException))
    = 0;

  /**
   * Check validity of the current attribute definition being built.
   *
   * @retval 0 if the attribute is not a valid combo.
   */
  virtual int validAttr (void) = 0;

  /**
   * Dump the content of the attribute definition.
   */
  virtual void dump (void) = 0;
};

/**
 * @ class ACEXML_Attributes_Def_Builder Attributes_Def_Builder.h "common/Attributes_Def_Builder.h"
 *
 * @ brief An abstract virtual class defining an interface
 *         for building attribute definitions from DTD.
 *
 * This class should be invisible to application programmers and
 * is only used for validator implementors.
 */
class ACEXML_Export ACEXML_Attributes_Def_Builder
{
public:

  typedef auto_ptr<ACEXML_Attributes_Def_Builder> VAR;

  virtual ~ACEXML_Attributes_Def_Builder () = 0;

  /**
   * Set the element name that the attribute builder applies.
   *
   * @retval 0 if valid, -1 otherwise.
   */
  virtual int setElement (const ACEXML_Char *namespaceURI,
                          const ACEXML_Char *localName,
                          const ACEXML_Char *qName,
                          ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    = 0;

  /**
   * Acquire an Attribute_Builder.
   */
  virtual ACEXML_Attribute_Def_Builder *getAttribute_Def_Builder () = 0;

  /**
   * Add a definition for one attribute.
   */
  virtual int insertAttribute (ACEXML_Attribute_Def_Builder *def,
                               ACEXML_Env &xmlenv) = 0;


  /**
   * Dump the content of the attribute definition.
   */
  virtual void dump (void) = 0;
};

#endif /* _ACEXML_ATTRIBUTES_DEF_BUILDER_H_ */
