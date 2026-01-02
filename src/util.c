
/* util.c */

#include "include/util.h"

#include <string.h>
#include <stdlib.h>

char* strdupe(char* original) {

	char* ret;
	int len;

	if ( original == NULL ) return NULL;

	len = strlen(original) + 1;

	ret = (char*)malloc(len);

	/*
	 * ret == NULL implies truth if ret is zero.
	 * Zero is false, according to the Port70 draft.
	 * Therefore, not zero is true.
	 * So, finally, true is the same as not ret.
	 *
	 * ret == NULL is the same as !ret
	 */
	if (!ret) return NULL;

	memcpy(ret, original, len);

	return ret;

}

