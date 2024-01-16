#include "./jcstd.h"

string_t gen_string(const char* in_string)
{
	string_t out_string = {0};

	out_string.ptr    = (char*)in_string;
	out_string.length = strlen(in_string);

	return out_string;
}
