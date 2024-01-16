#include <errno.h>

#include "../../outils/outils.h"
#include "file_reader.h"


char* file_read_buffer_until(char delimiter, FILE* file)
{
	char* buffer = NULL;
	u64 buffer_len = 0;
	char c = '\0';
	u64 i;

	ASSERT(file != NULL)

	while((c = getc(file)) != EOF)
	{
		if(c == delimiter)
		{
			INFO("Found delimiter")
			ungetc(c, file);
			break;
		}

		buffer_len++;
	}


	if(ferror(file)) goto error;
	if(fseek(file, -buffer_len, SEEK_CUR) == -1) goto error;

	buffer = malloc(buffer_len * sizeof(char));
	if(buffer == NULL) goto error;

	for(i = 0; i < buffer_len; ++i)
		buffer[i] = fgetc(file);

	return buffer;

error:
	free(buffer);

	ERROR(strerror(errno));
	clearerr(file);

	return NULL;
}


bool file_read_until(char delimiter, FILE* file)
{
	char c = '\0';

	ASSERT(file != NULL)

	while((c = getc(file)) != EOF)
	{
		if(c != delimiter) continue;

		INFO("Found delimiter")
		ungetc(c, file);
		break;
	}

	if(ferror(file)) goto error;

	return false;

error:
	ERROR(strerror(errno));
	clearerr(file);

	return true;
}
