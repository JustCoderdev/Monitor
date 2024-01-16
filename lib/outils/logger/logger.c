#include "logger.h"

#include <stdio.h>

#include <errno.h>

#include "../sgr/sgr.h"

u8 log_level_color_internal(log_level level)
{
	switch(level)
	{
		/* clang-format off */
		case LOG_TRACE: return 0;
		case LOG_INFO:  return 6;
		case LOG_DEBUG: return 2;
		case LOG_WARN:  return 3;
		case LOG_ERROR: return 1;
		case LOG_FATAL: return 5;
			/* clang-format on */
	}
}

literal log_level_string_internal(log_level level)
{
	switch(level)
	{
		/* clang-format off */
		case LOG_TRACE: return "TRACE";
		case LOG_INFO:  return "INFO ";
		case LOG_DEBUG: return "DEBUG";
		case LOG_WARN:  return "WARN ";
		case LOG_ERROR: return "ERROR";
		case LOG_FATAL: return "FATAL";
			/* clang-format on */
	}
}


void log_msg_internal(log_level level, char* msg, char* file, int line)
{
	/* clang-format off */
	fprintf(LOG_STREAM,
			CSI RESET Z BOLD Z FG_WHITE Z "3%d" M "%s"
			CSI RESET Z FG_BR_BLACK  M " [%s:%d] "
			CSI RESET                M "%s\n",
			log_level_color_internal(level), log_level_string_internal(level), file, line, msg);
	/* clang-format on */
}


void log_trace_internal(char* msg, char* file, int line)
{
	log_msg_internal(LOG_TRACE, msg, file, line);
}

void log_info_internal(char* msg, char* file, int line)
{
	log_msg_internal(LOG_INFO, msg, file, line);
}

void log_debug_internal(char* msg, char* file, int line)
{
	log_msg_internal(LOG_DEBUG, msg, file, line);
}

void log_warn_internal(char* msg, char* file, int line)
{
	log_msg_internal(LOG_WARN, msg, file, line);
}

void log_error_internal(char* msg, char* file, int line)
{
	log_msg_internal(LOG_ERROR, msg, file, line);
}

void log_errno_internal(char* msg, int error_code, char* file, int line)
{
	/* clang-format off */
	fprintf(LOG_STREAM,
			CSI RESET Z BOLD Z FG_WHITE Z FG_RED M "ERROR"
			CSI RESET Z FG_BR_BLACK              M " [%s:%d] "
			CSI RESET                            M "%s \\ \n"
			CSI UNDERLINE                        M "errno(%d) message"
			CSI RESET                            M ": %s\n",
			 file, line, msg, error_code, strerror(error_code));
	/* clang-format on */
}

void log_fatal_internal(char* msg, char* file, int line)
{
	/* clang-format off */
	fprintf(LOG_STREAM,
			/* CSI RESET Z BOLD    Z BG_MAGENTA Z FG_WHITE    M " FATAL " */
			CSI RESET Z BOLD Z BG_BLACK Z FG_WHITE M " FATAL "
			CSI RESET Z FG_BR_BLACK                M " [%s:%d] "
			CSI RESET                              M "%s\n",
			file, line, msg);
	/* clang-format on */

	exit(1);
}


void log_assert_internal(bool assertion, char* expression, char* file, int line)
{
	if(assertion) return;

	/* clang-format off */
	fprintf(LOG_STREAM,
			CSI RESET Z BOLD    Z BG_RED   Z FG_WHITE M " ASSERT "
			CSI RESET Z FG_BR_BLACK                   M " [%s:%d] "
			CSI RESET                                 M "Assertion failed: \"%s\"\n",
			file, line, expression);
	/* clang-format on */

	exit(1);
}
