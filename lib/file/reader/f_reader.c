#include <errno.h>

#include "../../outils/outils.h"
#include "file_reader.h"


string file_read_buffer_until(char delimiter, FILE* file)
{
	char* buffer = NULL;
	size buffer_len = 0;
	char c = '\0';
	m_nat i;

	INFO("Reading buffer")
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
	clearerr(file);

	ERROR(strerror(errno));
	return NULL;
}



string file_read_until(char delimiter, FILE* file)
{
	(void)delimiter;
	(void)file;

	FATAL("\"file_read_until\" Not implemented")
	return NULL;
}
