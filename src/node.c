
/* node.c */

#include "include/node.h"
#include "include/nodevec.h"
#include "include/bool.h"
#include "include/ecode.h"

#include <stdlib.h>

node* newNode(nodetype nt) {

	node* ret;

	ret = (node*)malloc(sizeof(node));
	if (!ret) return NULL;

	ret->nt = nt;
	ret->allocated = TRUE;

	/* Init setting */
	ret->attrs = NULL;
	ret->name = NULL;
	ret->text = NULL;

	if ( nt == NODE_TYPE_ELEMENT ) {
		(ret->children).count = 0;
		(ret->children).capacity = 0;
		(ret->children).items = NULL;
	}

	return ret;

}

ecode addChild(node* parent, node* child) {

	if ( parent->nt != NODE_TYPE_ELEMENT ) return ECODE_FAIL_BADARG;
	if ( !parent || !child ) return ECODE_FAIL_BADARG;

	vecAppend(&parent->children, child);

	return ECODE_SUCCESS;

}

