
#include "include/node.h"

#include <stdlib.h>

int main(void) {

	node *head =
		wrapped("html", "",
			wrapped("body", "",
				wrapped("h1", "color=\"red\"",
					puretext("Hi! "),
					wrapped("i", "",
						puretext("Here's some italic text!"),
						NULL
					),
					NULL
				),
				single("hr", "width=\"50%\""),
				puretext("Some text"),
				NULL
			),
			NULL
		);

	printNode(head);
	putchar('\n');
	freeNode(head);

	return EXIT_SUCCESS;

}
