#ifndef __APPLE__
extern const int TRANSLATION_MOCK;
#else

#include "../device.h"

float device_cpu_usage(void)
{
	return -37.34f;
}

float device_cpu_temperature(void)
{
	return -74.12f;
}

#endif
