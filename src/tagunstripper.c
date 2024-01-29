#include <errno.h>

#define LOG_STREAM stdout

#include "../lib/file/reader/file_reader.h"
#include "../lib/jcstd/jcstd.h"
#include "../lib/outils/outils.h"

/* Move cusor to position */
/* Returns 1 if an error occurs */
bool file_insert_char(const u64 position, const char character, FILE *file)
{
	char tmp, c;
	u64 i;

	log_assert(file != NULL);

	for(tmp = character, i = position; tmp != EOF; ++i)
	{
		fseek(file, i, SEEK_SET);
		c = getc(file);

		printf("[%ld] c = (%d, '%c'),\ttmp = (%d, '%c')\n",
			   ftell(file),
			   c,
			   c,
			   tmp,
			   tmp);

		fseek(file, -1, SEEK_CUR);
		putc(tmp, file);

		tmp = c;
	}

	fseek(file, position, SEEK_SET);


	if(ferror(file))
	{
		log_errno("Error reading file");
		clearerr(file);
		return true;
	}

	return false;
}

/* The cursor get resetted to previous location ([27] -> [27]) */
/* Returns 1 if an error occurs */
bool file_remove_char_last(const char character, FILE *file)
{
	char tmp, c;
	u64 i, off_frm_end = 1;

	log_assert(file != NULL);

	do {
		fseek(file, -off_frm_end, SEEK_END);
		c = getc(file);

		printf( "Char at [%ld, %lu] is %d (%c)\n", ftell(file), off_frm_end, c, c);

		if(c == character) {
			log_info("Found character!");
			break;
		}

		off_frm_end++;
	} while(c != EOF);

	log_assert(off_frm_end > 0);

	printf("\n--- Now backwards! ---\n\n");

	for(tmp = ' ', i = 1; i <= off_frm_end; ++i)
	{
		fseek(file, -i, SEEK_END);
		c = getc(file);

		printf("[%ld] c = (%d, '%c'),\ttmp = (%d, '%c')\n",
			   ftell(file),
			   c,
			   c,
			   tmp,
			   tmp);

		fseek(file, -1, SEEK_CUR);
		putc(tmp, file);

		tmp = c;
	}

	fseek(file, -1, SEEK_CUR);


	if(ferror(file))
	{
		log_errno("Error reading file");
		clearerr(file);
		return true;
	}

	return false;
}

/* Returns 1 if error occurs */
bool file_remove_char_first(FILE *file)
{
	char tmp, c;
	u64 i, off_frm_end;

	log_assert(file != NULL);

	for(off_frm_end = 0; (c = getc(file)) != EOF; ++off_frm_end)
		;
	/* printf( "Char at [%ld, %lu] is %d (%c)\n", ftell(file), off_frm_end, c,
	 * c); */

	log_assert(off_frm_end > 0);

	/* printf("\n--- Now backwards! ---\n\n"); */

	for(tmp = ' ', i = 1; i <= off_frm_end; ++i)
	{
		fseek(file, -i, SEEK_END);
		c = getc(file);

		/* printf("[%ld] c = (%d, '%c'),\ttmp = (%d, '%c')\n", */
		/* 	   ftell(file), */
		/* 	   c, */
		/* 	   c, */
		/* 	   tmp, */
		/* 	   tmp); */

		fseek(file, -1, SEEK_CUR);
		putc(tmp, file);

		tmp = c;
	}

	fseek(file, -1, SEEK_CUR);


	if(ferror(file))
	{
		log_errno("Error reading file");
		clearerr(file);
		return true;
	}

	return false;
}


/* Returns 1 if an error occurs and logs */
bool file_move_until_last(char delimiter, FILE *file)
{
	char c = '\0';
	u64 off_frm_end = 1;

	log_assert(file != NULL);

	do {
		fseek(file, -off_frm_end, SEEK_END);
		c = getc(file);

		printf( "Char at [%ld, %lu] is %d (%c)\n", ftell(file), off_frm_end, c, c);

		if(c == delimiter) {
			log_info("Found character!");
			break;
		}

		off_frm_end++;
	} while(c != EOF);

	ungetc(c, file);


	if(ferror(file))
	{
		log_errno("Error reading file");
		clearerr(file);
		return true;
	}

	return false;
}

int main(int argc, char **argv)
{
	const char * const FILE_PATH = argv[1];
	FILE *file_to_unstrip = NULL;

	if(argc != 2)
		log_fatal("Missing path:\nusage: $ tagunstripper <path_to_file>");

	file_to_unstrip = fopen(FILE_PATH, "r+");
	if(file_to_unstrip == NULL)
	{
		log_errno("Could not access file");
		exit(1);
	}

	file_move_until_last('-', file_to_unstrip);
	file_insert_char(ftell(file_to_unstrip), '-', file_to_unstrip);

	fclose(file_to_unstrip);
	return EXIT_SUCCESS;
}
