
/* nodevec.h */

#ifndef HTMLC_NODEVEC_H
#define HTMLC_NODEVEC_H

#include "ecode.h"

/*
 * Nodes contain node vectors (children).
 * Node vectors contain nodes.
 *
 * This is a circular dependency.
 * Solved by forward-declaring.
 */
struct _node;

typedef struct _nodevec {

	/* List of node pointers */
	struct _node** items;

	int capacity;
	int count;

} nodevec;

/*
 * Appends node to the node vector.
 * Return ECODE_SUCCESS if all is well, or
 * ECODE_FAIL_ALLOC if the vector can't reallocate memory.
 */
ecode vecAppend( nodevec* nv, struct _node* item );

#endif

