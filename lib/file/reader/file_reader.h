#include "../../jcstd/jcstd.h"
#include "../../outils/outils.h"

#ifndef FILE_READER_H
#define FILE_READER_H

/* ----- Buffer traversed content -----
 * Return a pointer to a string of the content until specified
 * ---------- */
extern string file_read_buffer_until(char delimiter, FILE* file);


/* ----- Move cursor -----
 * Move cursor position until specified content
 * ---------- */
extern string file_read_until(char delimiter, FILE* file);


#endif

