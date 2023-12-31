#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "../lib/jcstd/jcstd.h"
#include "../lib/outils/o_sgr.h"
#include "../lib/device/device.h"
#include "../lib/outils/logger.h"

void log_error(string msg, string file, int line)
{
	/* clang-format off */
	fprintf(stderr,
			CSI RESET Z BOLD Z FG_PAL(196) M "ERROR "
			CSI RESET Z DIM  Z FG_WHITE    M "[%s:%d] "
			CSI RESET                      M "%s\n",
			file, line, msg);
	/* clang-format on */
}

void term_clear(void);
void term_altbuff_enter(void);
void term_altbuff_exit(void);

int main(void /* int argc, char *argv[] */)
{
#define DEBUG 0
#if DEBUG

	ERROR("Number < 0");
	printf("I'm very " CSI BOLD M "bold" CSI RESET M "\n");
	print_8bit_palette();

	return EXIT_SUCCESS;
#endif

#if !DEBUG
#undef DEBUG

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

