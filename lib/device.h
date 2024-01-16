#include <errno.h>

#include "../lib/file/reader/file_reader.h"
#include "device/device_internal.h"
#include "jcstd/jcstd.h"

#ifndef DEVICE_LIB_H
#define DEVICE_LIB_H

/* ------  Operating System  ------
 * [ ] name ("macOS Monterey")
 * [ ] uptime (time) */

extern char* os_name(void);
extern char* os_uptime(void);


/* ------  Network  ------
 * [ ] ssid (“Webpocket”)
 * [ ] address (address, “Disconnected”) */


/* ------  CPU  ------
 * [ ] usage (%)
 * [ ] temperature (*C) */

#endif
