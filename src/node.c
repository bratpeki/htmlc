
#include "include/node.h"
#include "include/util.h"

node* newNode(nodeType type) {
	node* n = calloc(1, sizeof *n);
	if ( n != NULL ) n->type = type;
	return n;
}

void appendChild(node* parent, node* child) {

	node *c;

	if ( parent->child == NULL ) {
		parent->child = child;
		return;
	}

	c = parent->child;
	while (c->next) c = c->next;
	c->next = child;

}

void freeNode(node *n) {

	node *c;
	node *next;

	if (!n) return;

	for (c = n->child; c; ) {
		next = c->next;
		freeNode(c);
		c = next;
	}

	free(n->name);
	free(n->params);
	free(n->text);
	free(n);

}

void printNode(node *n) {

	node *c;

	if (!n) return;

	if (n->type == NODE_TEXT) {
		fputs(n->text, stdout);
		return;
	}

	printf("<%s", n->name);
	if (n->params && *n->params)
		printf(" %s", n->params);

	if (n->type == NODE_VOID) {
		fputs(" />", stdout);
		return;
	}

	putchar('>');

	for (c = n->child; c; c = c->next)
		printNode(c);

	printf("</%s>", n->name);

}

node *wrapped(char *name, char *params, ...) {

	va_list ap;
	node* n;
	node* child;

	n = newNode(NODE_ELEMENT);

	n->name = strdup(name);
	n->params = strdup(params);

	va_start(ap, params);
	for (;;) {
		child = va_arg(ap, node *);
		if (!child) break;
		appendChild(n, child);
	}
	va_end(ap);

	return n;

}

node *single(char *name, char *params) {

	node* n;

	n = newNode(NODE_VOID);

	n->name = strdup(name);
	n->params = strdup(params);

	return n;

}

node *puretext(char *text) {

	node* n;

	n = newNode(NODE_TEXT);

	n->text = strdup(text);

	return n;

}

