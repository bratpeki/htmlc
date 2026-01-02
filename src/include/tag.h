
/* tag.h */

#ifndef HTMLC_TAG_H
#define HTMLC_TAG_H

#include "node.h"

/*
 * Allocate a new element tag with all it's children in a variadic argument list
 * The last variadic argument has to be NULL.
 */
node* el( char* name, char* attrs, ... );

/* Allocate a new void tag */
node* vd( char* name, char* attrs );

/* Allocate text */
node* tx( char* text );

#endif

