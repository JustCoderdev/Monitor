#include <errno.h>

#include "../../outils/outils.h"
#include "file_reader.h"


char *file_read_buffer_until(char delimiter, FILE *file)
{
	char *buffer = NULL;
	u64 buffer_len = 0;
	char c = '\0';
	u64 i;

	log_assert(file != NULL);
	while((c = getc(file)) != EOF)
	{
		if(c == delimiter)
		{
			ungetc(c, file);
			break;
		}

		buffer_len++;
	}

	if(ferror(file))
	{
		log_errno("Error reading a file");
		clearerr(file);

		return NULL;
	}

	if(fseek(file, -buffer_len, SEEK_CUR) == -1)
	{
		log_errno("Error moving cursor in file");
		clearerr(file);

		return NULL;
	}

	buffer = malloc(buffer_len * sizeof(char));
	if(buffer == NULL)
	{
		free(buffer);

		log_errno("Not enough memory for buffering");
		clearerr(file);

		return NULL;
	}


	for(i = 0; i < buffer_len; ++i)
		buffer[i] = fgetc(file);

	return buffer;
}


bool file_read_until(char delimiter, FILE *file)
{
	char c = '\0';

	log_assert(file != NULL);
	while((c = getc(file)) != EOF)
	{
		if(c != delimiter) continue;

		ungetc(c, file);
		break;
	}

	if(ferror(file))
	{
		log_errno("Error reading a file");
		clearerr(file);

		return true;
	}

	return false;
}
