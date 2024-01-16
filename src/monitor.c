#include <errno.h>
#include <unistd.h>

#include "../lib/device.h"
#include "../lib/file/reader/file_reader.h"
#include "../lib/jcstd/jcstd.h"
#include "../lib/outils/outils.h"

void term_clear(void);
void term_altbuff_enter(void);
void term_altbuff_exit(void);


int main(int argc, char* argv[])
{
	ASSERT(sizeof(s8) == 1)
	ASSERT(sizeof(s16) == 2)
	ASSERT(sizeof(s32) == 4)
	ASSERT(sizeof(s64) == 8)

#if 1
	(void)argc;
	(void)argv;

#else
	FILE* file = fopen("../test.txt", "r");
	char* buffer;

	(void)argc;
	(void)argv;

	(void)file_read_until('[', file);
	buffer = file_read_buffer_until(']', file);

	if(file == NULL) goto error;
	if(buffer == NULL) goto error;

	printf("buffer: '%s'\n", buffer);

error:
	ERRNO("AAAAAA")
	return EXIT_FAILURE;

	/* #else */

	const u8 UPDATE_RATE_S = 1;
	u8 iterations = 15;

	if(argc == 2) iterations = atoi(argv[1]);

	setvbuf(stdout, NULL, _IOFBF, 0);
	term_altbuff_enter();

	while(--iterations > 0)
	{
		term_clear();

		printf("Remaining %us\n", iterations * UPDATE_RATE_S);
		putchar('\n');

		printf("OPERATING SYSTEM\n");
		printf(" .name: %s\n", os_name());
		printf(" .uptime: %s\n", os_uptime());
		putchar('\n');

		printf("NETWORK\n");
		printf(" .ssid: %s\n", "WebpocketTest");
		printf(" .address: %s\n", "Disconnected"); /* 192.168.1.150 */
		putchar('\n');

		printf("CPU\n");
		printf(" .usage: %.1f%%\n", -37.34f);
		printf(" .temp: %.1f%%\n", -74.12f);
		putchar('\n');

		/* RAM
		 * [ ] usage (%)
		 * [ ] used (Gb)
		 * [ ] total (Gb) */

		/* Memory
		 * [ ] usage (%)
		 * [ ] used (Gb)
		 * [ ] total (Gb) */

		/* Battery
		 * [ ] stored (%)
		 * [ ] status (“charging”, “discharging”)
		 * [ ] time until depleted (time)
		 * [ ] time until full (time) */

		/* Power
		 * [ ] source (“socket”, “battery”)
		 * [ ] draw (W) */

		putchar('\n');
		printf("Press ^C to quit: ");

		fflush(stdout);
		sleep(UPDATE_RATE_S);
	}

	term_altbuff_exit();
#endif

	return EXIT_SUCCESS;
}



void term_clear(void)
{
	/* system("clear"); */

	/* Clear screen */
	printf(CSI "2J");

	/* Move to cursor home (upper left) */
	printf(CSI "H");
}

void term_altbuff_enter(void)
{
	printf(CSI "?1049h" CSI "H");
}

void term_altbuff_exit(void)
{
	printf(CSI "?1049l");
}
