#ifdef __APPLE__

#include <errno.h>
#include <sys/sysctl.h>

#include "../jcstd/jcstd.h"
#include "../outils/logger.h"
#include "device.h"

#define SYS_ERROR -1


string os_name(void)
{
	/* man 3 sysctl */

	/* kern.hostname  */
	/* kern.ostype    */
	/* kern.osrelease */
	/* kern.version   */

	char* p;
	size_t len;
	if(sysctlbyname("hw.model", NULL, &len, NULL, 0) == SYS_ERROR)
	{
		ERROR(strerror(errno));
		return "Error";
	}

	p = malloc(len);
	if(sysctlbyname("hw.model", p, &len, NULL, 0) == SYS_ERROR)
	{
		ERROR(strerror(errno));
		return "Error";
	}

	return p;
}


string os_uptime(void)
{
	return "14h 15m 13s";
}


#endif
