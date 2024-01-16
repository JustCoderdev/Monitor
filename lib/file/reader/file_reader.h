#ifndef FILE_READER_H
#define FILE_READER_H

#include "../../jcstd/jcstd.h"
#include "../../outils/outils.h"


/* ------  Buffer traversed content  ------
 * Return a pointer to a string of the content until specified */

/* Returns NULL if an error occured and logs error */
extern char* file_read_buffer_until(char delimiter, FILE* file);


/* ------  Move cursor  ------
 * Move cursor position until specified content */

/* Returns 1 if an error occured and logs error */
extern bool file_read_until(char delimiter, FILE* file);


#endif

