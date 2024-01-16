#ifndef __APPLE__
extern const int TRANSLATION_MOCK;
#else

#include <errno.h>
#include <sys/sysctl.h>
#include <time.h>

#include "../device.h"
#include "../jcstd/jcstd.h"
#include "../outils/outils.h"

#define SYS_ERROR -1

char *device_os_name(void)
{
	static char *name = NULL;

	if(name != NULL) return name;

	{
		literal NAME_KEY = "kern.hostname";
		u64 name_len;


		if(sysctlbyname(NAME_KEY, NULL, &name_len, NULL, 0) == SYS_ERROR)
		{
			log_errno("Error executing sysctl");
			return "error";
		}

		name = malloc(name_len);
		if(sysctlbyname(NAME_KEY, name, &name_len, NULL, 0) == SYS_ERROR)
		{
			free(name);
			log_errno("Error executing sysctl");
			return "error";
		}

		return name;
	}
}

char *device_os_uptime(void)
{
	struct timeval boot_time = {0};
	u64 len = sizeof(boot_time);

	const time_t now_time = time(0);
	const struct tm * const tm = localtime(&now_time);

	const s8 OUT_LEN = 16;
	char *out = malloc(OUT_LEN);

	struct timespan_t timespan;

	if(tm == NULL) goto error;
	if(out == NULL) goto error;

	if(sysctlbyname("kern.boottime", &boot_time, &len, NULL, 0) == SYS_ERROR)
		goto error;

	timespan = timespan_from_seconds(now_time - boot_time.tv_sec);
	if(snprintf(out,
				OUT_LEN,
				"%dd %dh %dm %ds",
				timespan.d,
				timespan.h,
				timespan.m,
				timespan.s)
	   == -1)
		goto error;

	return out;

error:
	free(out);

	log_errno(":D");
	return "error";
}

#undef SYS_ERROR
#endif
