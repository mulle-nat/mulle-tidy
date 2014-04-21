//
//  delegate.c
//  mulle-tidy
//
//  Created by Nat! on 01.02.14.
//  Copyright (c) 2014 Mulle kybernetiK. All rights reserved.
//

#include "config.h"

#include "tidy-int.h"
#include "forward.h"


static void   nop_start_element( TidyDoc doc, TidyNode node, void *userApp)
{
}


static void   nop_end_element( TidyDoc doc, TidyNode node, void *userApp)
{
}


static void   nop_element_value_utf8_characters( TidyDoc doc, void *s, size_t len, void *userApp)
{
}


static void   nop_other_element( TidyDoc doc, TidyNode node, void *userApp)
{
}



void TY_( InitDelegate( TidyDocImpl *doc ))
{
   doc->delegate.start_element                 = nop_start_element;
   doc->delegate.end_element                   = nop_end_element;
   doc->delegate.element_value_utf8_characters = nop_element_value_utf8_characters;
   doc->delegate.other_element                 = nop_other_element;
}
                

void   tidySetParserDelegate( TidyDoc _doc, TidyParserDelegate *delegate, size_t size)
{
   TidyDocImpl  *doc;

   assert( size == sizeof( TidyParserDelegate));
   
   doc = (TidyDocImpl *) _doc;
   doc->delegate.start_element = delegate->start_element ? delegate->start_element : nop_start_element;
   doc->delegate.end_element   = delegate->end_element ? delegate->end_element : nop_end_element;
   doc->delegate.element_value_utf8_characters   = delegate->element_value_utf8_characters ? delegate->element_value_utf8_characters : nop_element_value_utf8_characters;
   doc->delegate.other_element   = delegate->other_element ? delegate->other_element : nop_other_element;
}


size_t   tidyGetParserDelegate( TidyDoc _doc, TidyParserDelegate *delegate, size_t size)
{
   TidyDocImpl  *doc;

   if( size < sizeof( TidyParserDelegate))
      return( sizeof( TidyParserDelegate));
   
   doc = (TidyDocImpl *) _doc;
   memset( delegate, 0, sizeof( TidyParserDelegate));
   if( delegate->start_element != nop_start_element)
      delegate->start_element = doc->delegate.start_element;
   if( delegate->end_element != nop_end_element)
      delegate->end_element = doc->delegate.end_element;
   if( delegate->element_value_utf8_characters != nop_element_value_utf8_characters)
      delegate->element_value_utf8_characters = doc->delegate.element_value_utf8_characters;
   if( delegate->other_element != nop_other_element)
      delegate->other_element = doc->delegate.other_element;

   return( 0);
}

