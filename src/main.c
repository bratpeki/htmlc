
/* main.c */

#include "include/bool.h"
#include "include/node.h"
#include "include/tag.h"
#include "include/tree.h"

#include <stdlib.h>
#include <stdio.h>

#define STATIC_VD( dest, nname, aattrs ) \
	(dest).nt = NODE_TYPE_VOID; \
	(dest).name = nname; \
	(dest).attrs = aattrs; \
	(dest).allocated = FALSE;

int main(void) {

	/* Main node */
	node* head;

	/* Reusable elements */
	node reusable1;
	node reusable2;

	STATIC_VD(reusable1, "hr", "width=\"25%\"");
	STATIC_VD(reusable2, "hr", "width=\"100%\"");

	head =
		el("html", NULL,
			el("body", NULL,
				el("h1", "color=\"red\"",
					tx("Hi! "),
					el("i", NULL,
						tx("Here's some italic text!"),
						NULL
					),
					NULL
				),
				&reusable1,
				vd("hr", "width=\"50%\""),
				&reusable1,
				&reusable2,
				&reusable1,
				tx("Some text"),
				NULL
			),
			NULL
		);

	printTree(head, 0);
	putchar('\n');
	freeTree(head);

	return EXIT_SUCCESS;

}

