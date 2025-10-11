#ifndef STRINGS_H
#define STRINGS_H

#include "lib/standard_lib.h"

int strcmp(const char *s1, const char *s2);
size_t strlen(char *string);
char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, size_t n);

#endif