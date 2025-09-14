#ifndef BOOL_H
#define BOOL_H


typedef enum {
	bool_false = 0,
	bool_true = 1,
} bool_t; // could cause issues

#define true bool_true
#define false bool_false


#endif