#ifndef __linux__
extern const int TRANSLATION_MOCK;
#else

#include "../device.h"

float device_cpu_usage(void)
{
	static u64 last_tot_user = 0, last_tot_low = 0, last_tot_sys = 0,
			   last_tot_idle = 0;

	float percent;
	u64 tot_user, tot_low, tot_sys, tot_idle;

	FILE *file;
	file = fopen("/proc/stat", "r");
	fscanf(
		file, "cpu %lu %lu %lu %lu", &tot_user, &tot_low, &tot_sys, &tot_idle);
	fclose(file);

	if(tot_user < last_tot_user || tot_low < last_tot_low
	   || tot_sys < last_tot_sys || tot_idle < last_tot_idle)
	{
		/* Overflow detection. Just skip this value. */
		return -1.0;
	}

	percent = (tot_user - last_tot_user) + (tot_low - last_tot_low)
			  + (tot_sys - last_tot_sys);

	percent /= (tot_idle - last_tot_idle);
	percent *= 100;


	last_tot_user = tot_user;
	last_tot_low = tot_low;
	last_tot_sys = tot_sys;
	last_tot_idle = tot_idle;

	return percent;
}

float device_cpu_temperature(void)
{
	return -74.12f;
}

#endif
