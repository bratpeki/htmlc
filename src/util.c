
#include "include/util.h"

#include <stdlib.h>
#include <string.h>

char *strdup(char *s) {

	char* p;

	if ( s == NULL ) return NULL;

	p = malloc(strlen(s) + 1);
	if ( p == NULL ) return NULL;

	strcpy(p, s);

	return p;

}

