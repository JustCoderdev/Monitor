extern const int TRANSLATION_MOCK;

#ifdef __linux__

#include "../outils/outils.h"
#include "device.h"

string os_name(void)
{
	FATAL("\"os_name(void)\" Not implemented!");
}

string os_uptime(void)
{
	FATAL("\"os_uptime(void)\" Not implemented!");
}

#endif
