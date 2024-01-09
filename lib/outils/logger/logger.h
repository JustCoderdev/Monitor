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



enum log_level_t {
	LOG_TRACE = 0,
	LOG_INFO,
	LOG_DEBUG,
	LOG_WARN,
	LOG_ERROR,
	LOG_FATAL
};

typedef const enum log_level_t log_level;
typedef enum log_level_t m_log_level;


extern nat log_level_color(log_level level);
extern string log_level_string(log_level level);

extern void log_msg(log_level level, string msg, string file, int line);

extern void log_trace(string msg, string file, int line);
extern void log_info(string msg, string file, int line);
extern void log_debug(string msg, string file, int line);
extern void log_warn(string msg, string file, int line);
extern void log_error(string msg, string file, int line);
extern void log_errno(string msg, int error_code, string file, int line);
extern void log_fatal(string msg, string file, int line);

extern void log_assert(bool assertion, string expression, string file,
					   int line);

#endif
