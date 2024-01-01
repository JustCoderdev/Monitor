#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "../lib/device/device.h"
#include "../lib/jcstd/jcstd.h"
#include "../lib/outils/outils.h"

void term_clear(void);
void term_altbuff_enter(void);
void term_altbuff_exit(void);

int main(void /* int argc, char *argv[] */)
{
#define DEBUGGING 1
#if DEBUGGING

	ERROR("Number < 0");
	printf("I'm very " CSI BOLD M "bold" CSI RESET M "\n");
	print_8bit_palette();

	FATAL("I'm an ugly error :)");
	exit(1);

	return EXIT_SUCCESS;
#endif

#if !DEBUGGING
#undef DEBUGGING

	nat UPDATE_RATE_S = 1;
	m_nat iterations  = 15;

	setvbuf(stdout, NULL, _IOFBF, 0);
	term_altbuff_enter();

	while(--iterations > 0)
	{
		term_clear();

		printf("Remaining %us\n", iterations);
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

		printf("Press ^C to quit: ");

		fflush(stdout);
		sleep(UPDATE_RATE_S);
	}

	term_altbuff_exit();
	return EXIT_SUCCESS;
#endif
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
