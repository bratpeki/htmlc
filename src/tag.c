
/* tag.c */

#include "include/tag.h"
#include "include/node.h"
#include "include/nodevec.h"
#include "include/util.h"

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

node* el( char* name, char* attrs, ... ) {

	va_list args;

	node* created;

	node* argnode;

	/* The second va_start argument is the argument before the ellipsis */
	va_start(args, attrs);

	/* Setting up the el node */

	created = newNode(NODE_TYPE_ELEMENT);
	created->name = strdupe(name);
	created->attrs = strdupe(attrs);
	(created->children).capacity = 0;
	(created->children).count = 0;

	/* Adding its children into the list */

	argnode = va_arg(args, node*);

	while ( argnode != NULL ) {
		vecAppend(&(created->children), argnode);
		argnode = va_arg(args, node*);
	}

	va_end(args);

	return created;

}

node* vd( char* name, char* attrs ) {

	node* created;

	created = newNode(NODE_TYPE_VOID);
	created->name = strdupe(name);
	created->attrs = strdupe(attrs);

	return created;

}

node* tx( char* text ) {

	node* created;

	created = newNode(NODE_TYPE_TEXT);
	created->text = strdupe(text);

	return created;

}

