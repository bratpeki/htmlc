
#ifndef HTMLC_NODE_H
#define HTMLC_NODE_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/*
 * Type of node,
 * - wrapped (element with children),
 * - single (void) or
 * - puretext
 */
typedef enum {

	NODE_ELEMENT, /* div, html, body, h1, b, p */
	NODE_VOID, /* br, hr */
	NODE_TEXT /* puretext */

} nodeType;

/*
 * One HTML node.
 */
typedef struct _node {

	nodeType type;

	char *name; /* tag name or NULL for text */
	char *params; /* raw attribute string or NULL */
	char *text; /* only for text nodes */

	struct _node *child;
	struct _node *next;

} node;

/*
 * Allocates memory and returns the pointer.
 * Returns if NULL if calloc failed.
 */
node* newNode(nodeType type);

/*
 * Append the child to the parent.
 *
 * If no child is named in the parent, make this child the child in the parent.
 * Otherwise, append it to the last next as next.
 */
void appendChild(node* parent, node* child);

/*
 * Recursively free the linked list.
 */
void freeNode(node *n);

/*
 * Recursively print the linked list.
 */
void printNode(node *n);

/*
 * Create a wrapping HTML tag node.
 */
node* wrapped(char *name, char *params, ...);

/*
 * Create a single (non-wrapping) HTML tag node.
 */
node* single(char *name, char *params);

/*
 * Create a puretext node.
 */
node* puretext(char *text);

#endif

