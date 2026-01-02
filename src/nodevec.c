
/* nodevec.c */

#include "include/nodevec.h"
#include "include/ecode.h"

#include <stdlib.h>

ecode vecAppend( nodevec* nv, struct _node* item ) {

	if ( nv->count >= nv->capacity ) {

		if ( nv->capacity == 0 ) nv->capacity = 2;
		else nv->capacity *= 2;

		nv->items = realloc(nv->items, nv->capacity * sizeof(*nv->items));
		if ( nv->items == NULL )
			return ECODE_FAIL_ALLOC;
	}

	nv->items[nv->count++] = (item);

	return ECODE_SUCCESS;

}

