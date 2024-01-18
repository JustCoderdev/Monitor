#include <errno.h>

#include "../lib/file/reader/file_reader.h"
#include "device/device_internal.h"
#include "jcstd/jcstd.h"

#ifndef DEVICE_LIB_H
#define DEVICE_LIB_H

/* ------  Operating System  ------
 * [x] name ("macOS Monterey")
 * [x] uptime (time) */

extern char *device_os_name(void);
extern char *device_os_uptime(void);


/* ------  Network  ------
 * [ ] ssid (“Webpocket”)
 * [ ] address (address, “Disconnected”) */

extern char *device_net_ssid(void);
extern char *device_net_address(void);


/* ------  CPU  ------
 * [ ] usage (%)
 * [ ] temperature (*C) */

extern float device_cpu_usage(void);
extern float device_cpu_temperature(void);


#endif
