#include "../jcstd/jcstd.h"
#include "../outils/outils.h"
#include "device_internal.h"

struct timespan_t timespan_from_seconds(const u64 seconds)
{
	struct timespan_t timespan = {0};
	u64 tmp;

	tmp = seconds;
	timespan.s = tmp % 60;

	tmp = (tmp - timespan.s) / 60;
	timespan.m = tmp % 60;

	tmp = (tmp - timespan.m) / 60;
	timespan.h = tmp % 60;

	timespan.d = (tmp - timespan.h) / 24;

	return timespan;
}
