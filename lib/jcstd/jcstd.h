#include <stdlib.h>

#include <string.h>

#ifndef JC_STD_H
#define JC_STD_H


#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define _STRING(VALUE) #VALUE
#define STRING(SYMBOL) _STRING(SYMBOL)


/* ----- Boolean definition -----
 * ----- ----- */
enum bool_t {
	true = (1 == 1),
	false = (1 != 1)
};

typedef const enum bool_t bool;
typedef enum bool_t m_bool;


/* ----- Natural numbers definition -----
 * ----- ----- */
typedef const unsigned int nat; /* %u */
typedef unsigned int m_nat;


/* ----- Character definition -----
 * ----- -----*/
/* typedef const unsigned char uchar;  /1* %c *1/ */
/* typedef unsigned char m_char;	   /1* %c *1/ */

typedef const char* const string;


/* ----- Various definition -----
 * ----- ----- */
typedef unsigned long size; /* %lu */


/* ----- Mutable string definition -----
 * -----  -----*/
typedef struct {
	char* ptr;
	size length;
} m_string;

m_string gen_string(const char* in_string);

#endif
