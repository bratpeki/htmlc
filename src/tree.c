
/* tree.c */

#include "include/node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACES_SEP "  "

void spaces(int depth) {
	int i;
	for ( i = 0; i < depth; i++ )
		printf(SPACES_SEP);
}

void printTree( node* head, int depth ) {

	int i;

	switch (head->nt) {

		case NODE_TYPE_ELEMENT:

			/* Print <html width=50%> */

			if ( head->attrs == NULL ) {
				spaces(depth);
				printf("<%s>\n", head->name);
			}

			else if ( strlen(head->attrs) == 0 ) {
				spaces(depth);
				printf("<%s>\n", head->name);
			}

			else {
				spaces(depth);
				printf("<%s %s>\n", head->name, head->attrs);
			}

			/* Resolve everything inside */
			for ( i = 0; i < (head->children).count; i++ ) {
				printTree(((head->children).items)[i], depth + 1);
			}

			/* Print </html> */
			spaces(depth);
			printf("</%s>\n", head->name);

			break;

		case NODE_TYPE_VOID:

			/* Print <a href="link.net"> */
			if ( head->attrs == NULL ) {
				spaces(depth);
				printf("<%s/>\n", head->name);
			}

			else if ( strlen(head->attrs) == 0 ) {
				spaces(depth);
				printf("<%s/>\n", head->name);
			}

			else {
				spaces(depth);
				printf("<%s %s/>\n", head->name, head->attrs);
			}

			break;

		case NODE_TYPE_TEXT:

			/* Just print the text */
			spaces(depth);
			printf("%s\n", head->text);

			break;

	}

}

void freeTree( node* head ) {

	int i;

	/* Free the children first */
	for ( i = 0; i < (head->children).count; i++ )
		freeTree(((head->children).items)[i]);

	/*
	 * Base case
	 * Free the head node
	 */
	if ( head->allocated ) {
		free((head->children).items);
		free(head);
	}

}

