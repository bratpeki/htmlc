
/* node.h */

#ifndef HTMLC_NODE_H
#define HTMLC_NODE_H

#include "ecode.h"
#include "bool.h"
#include "nodevec.h"

typedef enum _nodetype {
	NODE_TYPE_ELEMENT = 0, /* ex. html */
	NODE_TYPE_VOID = 1, /* ex. img */
	NODE_TYPE_TEXT = 2 /* ex. "This is some text" */
} nodetype;

typedef struct _node {

	/* Node type */
	nodetype nt;

	/*
	 * For NODE_TYPE_ELEMENT and NODE_TYPE_VOID
	 * ex. html, body, h1, img, div, etc.
	 */
	char* name;

	/*
	 * For NODE_TYPE_ELEMENT and NODE_TYPE_VOID
	 * ex. "width = 50%"
	 */
	char* attrs;

	/*
	 * For NODE_TYPE_ELEMENT
	 * Children node vector
	 */
	nodevec children;

	/*
	 * For NODE_TYPE_TEXT
	 */
	char* text;

	/*
	 * For all nodes
	 * Some items might be made by the programmer and not allocated
	 */
	bool allocated;

} node;

/*
 * Allocates memory for a new node and returns it.
 * Returns NULL if allocation failed.
 */
node* newNode(nodetype nt);

/*
 * Adds a child to the parent of type NODE_TYPE_ELEMENT.
 * Returns ECODE_SUCCESS or ECODE_FAIL_BADARG if:
 * 1. parent == NULL
 * 2. child == NULL
 * 3. parent.nt != NODE_TYPE_ELEMENT
 */
ecode addChild(node* parent, node* child);

#endif

