#include "logger.h"

#include <stdio.h>

#include "../sgr/sgr.h"

void log_fatal(string msg, string file, int line) {
	/* clang-format off */
	fprintf(stderr,
			CSI RESET Z BOLD Z FG_PAL(196) M "FATAL "
			CSI RESET Z DIM  Z FG_WHITE    M "[%s:%d] "
			CSI RESET                      M "%s\n",
			file, line, msg);
	/* clang-format on */
}

void log_error(string msg, string file, int line)
{
	/* clang-format off */
	fprintf(stderr,
			CSI RESET Z BOLD Z FG_PAL(196) M "ERROR "
			CSI RESET Z DIM  Z FG_WHITE    M "[%s:%d] "
			CSI RESET                      M "%s\n",
			file, line, msg);
	/* clang-format on */
}

void log_debug(string msg, string file, int line) {
	(void)msg;
	(void)file;
	(void)line;

	FATAL("\"log_debug\" Not implemented")
}
