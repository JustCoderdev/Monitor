#include <stdlib.h>
#include <string.h>

#ifndef JC_STD_H
#define JC_STD_H


/* Boolean definition */
enum bool_t {
	true  = (1 == 1),
	false = (1 != 1)
};

typedef const enum bool_t bool;
typedef enum bool_t m_bool;


/* Natural numbers (unsigned) definition */
typedef const unsigned int nat;
typedef unsigned int m_nat;

typedef unsigned long size; /* %lu */

/* String literal definition */
typedef const char* const string;

/* #define STR_Fmt "\"%s\"(%lu)" */
/* #define STR_ARG(string) string.ptr, string.length */

/* Mutable string definition */
typedef struct {
	char* ptr;
	size_t length;
} m_string;

m_string gen_string(const char* in_string) {
	m_string out_string = {0};

	out_string.ptr = (char*)in_string;
	out_string.length = strlen(in_string);

	return out_string;
}


#endif
