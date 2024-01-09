#ifndef __APPLE__
extern const int TRANSLATION_MOCK;
#else

#include <errno.h>
#include <sys/sysctl.h>
#include <time.h>

#include "../jcstd/jcstd.h"
#include "../outils/outils.h"
#include "device.h"

#define SYS_ERROR -1

string os_name(void)
{
	string NAME_KEY = "kern.hostname";
	static char* name = NULL;
	size name_len;

	if(name != NULL) return name;

	if(sysctlbyname(NAME_KEY, NULL, &name_len, NULL, 0) == SYS_ERROR)
		goto error;

	name = malloc(name_len);
	if(sysctlbyname(NAME_KEY, name, &name_len, NULL, 0) == SYS_ERROR)
		goto error;

	return name;

error:
	free(name);

	ERROR(strerror(errno));
	return "error";
}

struct timespan_t {
	m_nat s, m, h, d;
};
struct timespan_t timespan_from_seconds(nat seconds)
{
	struct timespan_t timespan = {0};
	m_nat tot_s, tot_m, tot_h;

	tot_s = seconds;
	timespan.s = tot_s % 60;

	tot_m = (tot_s - timespan.s) / 60;
	timespan.m = tot_m % 60;

	tot_h = (tot_m - timespan.m) / 60;
	timespan.h = tot_h % 60;

	timespan.d = (tot_h - timespan.h) / 24;
	return timespan;
}

string os_uptime(void)
{
	struct timeval boot_time = {0};
	size len = sizeof(boot_time);

	time_t now_time = time(0);
	const struct tm* const tm = localtime(&now_time);

	const int OUT_LEN = 16;
	char* out = malloc(OUT_LEN);

	struct timespan_t timespan;

	if(tm == NULL) goto error;
	if(out == NULL) goto error;

	if(sysctlbyname("kern.boottime", &boot_time, &len, NULL, 0) == SYS_ERROR)
		goto error;

	timespan = timespan_from_seconds(now_time - boot_time.tv_sec);
	if(snprintf(out, OUT_LEN, "%dd %dh %dm %ds", timespan.d, timespan.h,
				timespan.m, timespan.s)
	   == -1)
		goto error;

	return out;

error:
	free(out);

	ERROR(strerror(errno));
	return "error";
}

#undef SYS_ERROR
#endif
