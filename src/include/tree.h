
/* tree.h */

#ifndef HTMLC_TREE_H
#define HTMLC_TREE_H

#include "node.h"

/*
 * Recursively print the tree
 * depth is for the recusive call, just set it to 0
 */
void printTree( node* head, int depth );

/* Recursively free the allocated nodes of a tree */
void freeTree( node* head );

#endif

