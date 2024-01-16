#include <stdlib.h>

#include <string.h>

#ifndef JC_STD_H
#define JC_STD_H


#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define _STRING(VALUE) #VALUE
#define STRING(SYMBOL) _STRING(SYMBOL)


/* ------  Numbers definition  ------ */
typedef signed char s8;   /* %d or %c */
typedef unsigned char u8; /* %u or %c */

typedef signed short s16;   /* %d */
typedef unsigned short u16; /* %u */

typedef signed int s32;   /* %d */
typedef unsigned int u32; /* %u */

typedef signed long int s64;   /* %ld */
typedef unsigned long int u64; /* %lu */


/* ------  Boolean definition  ------ */
enum bool_t {
	true  = (u8)(1 == 1),
	false = (u8)(1 != 1)
};

typedef enum bool_t bool; /* %d */


/* ------  Natural numbers definition  ------ */
/* typedef unsigned int nat; /1* %u *1/ */


/* ------  Character definition  ------ */
typedef char* const literal;
typedef unsigned char uchar;  /* %c */


/* ------  Mutable string definition  ------ */
typedef struct {
	const char* ptr;
	u64 length;
} string_t;

string_t gen_string(const char* in_string);

#endif
