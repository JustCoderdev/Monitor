#ifndef DEVICE_LIB_INTERNAL_H
#define DEVICE_LIB_INTERNAL_H

#include "../jcstd/jcstd.h"

struct timespan_t {
	u8 s, m, h, d;
};


struct timespan_t timespan_from_seconds(const u64 seconds);


#endif /* DEVICE_LIB_INTERNAL_H */
