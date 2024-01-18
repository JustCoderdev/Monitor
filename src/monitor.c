#include <errno.h>
#include <signal.h>
#include <unistd.h>

#define LOG_STREAM stdout

#include "../lib/device.h"
#include "../lib/file/reader/file_reader.h"
#include "../lib/jcstd/jcstd.h"
#include "../lib/outils/outils.h"

void term_clear(void);
void term_altbuff_enter(void);
void term_altbuff_exit(void);

void handle_interrupt(int sig)
{
	printf("\nTerminated program (%d)\n", sig);
	exit(sig != 2);
}

int main(int argc, char *argv[])
{

#if 0
	printf("coso: %s\n", device_net_ssid());

	(void)argc;
	(void)argv;

#else
	const u8 UPDATE_RATE_S = 1;
	u8 iterations = ~1;

	if(argc == 2) iterations = atoi(argv[1]);


	/* Assert size coherence */
	log_assert(sizeof(s8) == 1);
	log_assert(sizeof(s16) == 2);
	log_assert(sizeof(s32) == 4);
	log_assert(sizeof(s64) == 8);


	signal(SIGINT, handle_interrupt);
	setvbuf(stdout, NULL, _IOFBF, 0);
	term_altbuff_enter();

	while(iterations-- > 0)
	{
		term_clear();

		printf("Remaining %us\n", iterations * UPDATE_RATE_S);
		putchar('\n');

		printf("OPERATING SYSTEM\n");
		printf(" .name: %s\n", device_os_name());
		printf(" .uptime: %s\n", device_os_uptime());
		putchar('\n');

		printf("NETWORK\n");
		printf(" .ssid: %s\n", device_net_ssid());
		printf(" .address: %s\n", device_net_address());
		putchar('\n');

		printf("CPU\n");
		printf(" .usage: %.2f%%\n", device_cpu_usage());
		printf(" .temp: %.2f%%\n", device_cpu_temperature());
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
