#include "../../jcstd/jcstd.h"

#ifndef OUTILS_LOGGER_LIB_H
#define OUTILS_LOGGER_LIB_H

#ifndef LOG_STREAM
#define LOG_STREAM stderr
#endif

#define log_trace(msg) log_trace_internal(msg, __FILE__, __LINE__)
#define log_info(msg)  log_info_internal(msg, __FILE__, __LINE__)
#define log_debug(msg) log_debug_internal(msg, __FILE__, __LINE__)
#define log_warn(msg)  log_warn_internal(msg, __FILE__, __LINE__)
#define log_error(msg) log_error_internal(msg, __FILE__, __LINE__)
#define log_fatal(msg) log_fatal(msg, __FILE__, __LINE__)

#define log_errno(msg) log_errno_internal(msg, errno, __FILE__, __LINE__)
#define log_assert(EXPR) log_assert_internal(EXPR, STRING(EXPR), __FILE__, __LINE__)

typedef enum {
	LOG_TRACE = 0,
	LOG_INFO,
	LOG_DEBUG,
	LOG_WARN,
	LOG_ERROR,
	LOG_FATAL
} log_level;


extern u8 log_level_color_internal(log_level level);
extern literal log_level_string_internal(log_level level);

extern void log_msg_internal(log_level level, char* msg, char* file, int line);

extern void log_trace_internal(char* msg, char* file, int line);
extern void log_info_internal(char* msg, char* file, int line);
extern void log_debug_internal(char* msg, char* file, int line);
extern void log_warn_internal(char* msg, char* file, int line);
extern void log_error_internal(char* msg, char* file, int line);
extern void log_errno_internal(char* msg, int error_code, char* file, int line);
extern void log_fatal_internal(char* msg, char* file, int line);

extern void log_assert_internal(bool assertion, char* expression, char* file, int line);

#endif
