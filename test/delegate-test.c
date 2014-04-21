//
//  main.c
//  delegate-test
//
//  Created by Nat! on 01.02.14.
//  Copyright (c) 2014 Mulle kybernetiK. All rights reserved.
//
#include "tidy.h"


static void   start_element( TidyDoc doc, TidyNode node, void *userInfo)
{
   printf( "<%s>", tidyNodeGetName( node));
}


static void   end_element( TidyDoc doc, TidyNode node, void *userInfo)
{
   printf( "</%s>\n", tidyNodeGetName( node));
}


static void   element_value( TidyDoc doc, void *start, size_t len, void *userInfo)
{
   printf( "%.*s", (int) len, start);
}


static TidyParserDelegate   delegate =
{
   start_element,
   element_value,
   end_element,
   NULL
};


int main(int argc, const char * argv[])
{
   TidyDoc   tdoc;
   int       rc;
   
   tdoc  = tidyCreate();
   
   tidySetParserDelegate( tdoc, &delegate, sizeof( delegate));
   tidySetAppData( tdoc, 0x1848);

   rc = tidyParseFile( tdoc, argv[ 1]);
   tidyRelease( tdoc);
   
   return( rc);
}

