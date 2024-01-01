#include "../../jcstd/jcstd.h"

#ifndef OUTILS_LOGGER_LIB_H
#define OUTILS_LOGGER_LIB_H

#define FATAL(MSG) log_fatal(MSG, __FILE__, __LINE__); exit(1);
#define ERROR(MSG) log_error(MSG, __FILE__, __LINE__)
#define DEBUG(MSG) log_debug(MSG, __FILE__, __LINE__)

extern void log_fatal(string msg, string file, int line);
extern void log_error(string msg, string file, int line);
extern void log_debug(string msg, string file, int line);

#endif
