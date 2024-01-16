#ifndef __linux__
extern const int TRANSLATION_MOCK;
/* #else */

#include <errno.h>
#include <time.h>
#include <unistd.h>

#include "../device.h"
#include "../jcstd/jcstd.h"
#include "../outils/outils.h"

char *device_os_name(void)
{
	static char *os_name = NULL;
	if(os_name != NULL) return os_name;

	{
		literal FILE_PATH = "/proc/sys/kernel/ostype";

		FILE *os_name_file = fopen(FILE_PATH, "r");
		if(os_name_file == NULL)
		{
			log_errno("Unable to read OS-type file");
			return "error: A";
		}

		os_name = file_read_buffer_until('\n', os_name_file);
		fclose(os_name_file);

		printf("Buffer content: '%*s'\n", 5, os_name);

		if(os_name == NULL) return "error: B";
	}

	return os_name;
}

char *device_os_uptime(void)
{
#define OUT_LENGTH 16
	literal FILE_PATH = "/proc/uptime";
	FILE *uptime_file = fopen(FILE_PATH, "r");
	char *buffer = NULL;
	char *out = malloc(OUT_LENGTH * sizeof(char));
	struct timespan_t uptime;

	if(uptime_file == NULL)
	{
		log_errno("Unable to read uptime file");
		return "Error";
	}

	buffer = file_read_buffer_until('.', uptime_file);
	fclose(uptime_file);

	if(buffer == NULL) return "Error";
	if(out == NULL)
	{
		log_errno("Unable to allocate memory for uptime output");
		return "Error";
	}

	uptime = timespan_from_seconds(atoi(buffer));
	free(buffer);

	if(snprintf(out,
				OUT_LENGTH,
				"%dd %dh %dm %ds",
				uptime.d,
				uptime.h,
				uptime.m,
				uptime.s)
	   == -1)
	{
		free(out);
		log_errno("Error occured while crafting uptime output string");
		return "Error";
	}

	return out;
}

#endif
