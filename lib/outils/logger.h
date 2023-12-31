#include "../jcstd/jcstd.h"

#ifndef OUTILS_LOGGER_LIB_H
#define OUTILS_LOGGER_LIB_H

#define ERROR(MSG) log_error(MSG, __FILE__, __LINE__)

extern void log_error(string msg, string file, int line);
extern void log_debug(string msg, string file, int line);
/* extern void log(string msg, string file, int line); */

#endif
