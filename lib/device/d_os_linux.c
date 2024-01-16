#ifndef __linux__
extern const int TRANSLATION_MOCK;
/* #else */

#include <errno.h>
#include <time.h>
#include <unistd.h>

#include "../device.h"
#include "../jcstd/jcstd.h"
#include "../outils/outils.h"

#define SYS_ERROR -1

char* os_name(void)
{
	static char* name = NULL;
	u64 name_len = 0;

	literal file_path = "/proc/sys/kernel/ostype";
	FILE* file_ostype = NULL;
	char c;
	u64 i;

	if(name != NULL) return name;

	file_ostype = fopen(file_path, "r");
	if(file_ostype == NULL) goto error;

	while((c = getc(file_ostype)) != EOF)
	{
		name_len++;
	}

	ASSERT(name_len != 0)
	name = malloc(name_len);

	rewind(file_ostype);
	for(i = 0; i < name_len; ++i)
	{
		name[i] = getc(file_ostype);
	}

	return name;


error:
	fclose(file_ostype);
	free(name);

	ERROR(strerror(errno));
	return "Error";
}

char* os_uptime(void)
{
	WARN("\"os_uptime\" not implemented in linux version");
	return "14h 15m 13s";
}

#undef SYS_ERROR
#endif
