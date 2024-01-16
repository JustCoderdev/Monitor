#include "../../jcstd/jcstd.h"

#ifndef OUTILS_LOGGER_LIB_H
#define OUTILS_LOGGER_LIB_H

#define TRACE(MSG) log_trace(MSG, __FILE__, __LINE__);
#define INFO(MSG)  log_info(MSG, __FILE__, __LINE__);
#define DEBUG(MSG) log_debug(MSG, __FILE__, __LINE__);
#define WARN(MSG)  log_warn(MSG, __FILE__, __LINE__);
#define ERROR(MSG) log_error(MSG, __FILE__, __LINE__);
#define ERRNO(MSG) log_errno(MSG, errno, __FILE__, __LINE__);
#define FATAL(MSG) log_fatal(MSG, __FILE__, __LINE__);

#define ASSERT(EXPR) log_assert(EXPR, STRING(EXPR), __FILE__, __LINE__);

typedef enum {
	LOG_TRACE = 0,
	LOG_INFO,
	LOG_DEBUG,
	LOG_WARN,
	LOG_ERROR,
	LOG_FATAL
} log_level;


extern u8 log_level_color(log_level level);
extern literal log_level_string(log_level level);
extern void log_msg(log_level level, char* msg, char* file, int line);

extern void log_trace(char* msg, char* file, int line);
extern void log_info(char* msg, char* file, int line);
extern void log_debug(char* msg, char* file, int line);
extern void log_warn(char* msg, char* file, int line);
extern void log_error(char* msg, char* file, int line);
extern void log_errno(char* msg, int error_code, char* file, int line);
extern void log_fatal(char* msg, char* file, int line);

extern void log_assert(bool assertion, char* expression, char* file, int line);

#endif
