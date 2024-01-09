#include "./jcstd.h"

m_string gen_string(const char* in_string)
{
	m_string out_string = {0};

	out_string.ptr = (char*)in_string;
	out_string.length = strlen(in_string);

	return out_string;
}
