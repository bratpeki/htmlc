
#ifndef HTMLC_UTIL_H
#define HTMLC_UTIL_H

/*
 * Allocates memory for an identical copy of s.
 * Copies info over.
 *
 * Returns the pointer to the copied info,
 * or NULL if copying couldn't happen or if s is NULL.
 */
char* strdup(char* s);

#endif

