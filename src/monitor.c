#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "../lib/jcstd/jcstd.h"
#include "../lib/outils/o_sgr.h"

#define ERROR(MSG) log_error(MSG, __FILE__, __LINE__)
void log_error(string msg, string file, int line)
{
	/* clang-format off */
	fprintf(stderr,
			CSI    BOLD Z       FG_PAL(196) M "ERROR "
			CSI NO_BOLD Z DIM Z FG_WHITE    M "[%s:%d] "
			CSI RESET                       M "%s\n",
			file, line, msg);
	/* clang-format on */
}

string os_name(void);
void term_clear(void);
void term_altbuff_enter(void);
void term_altbuff_exit(void);

int main(void /* int argc, char *argv[] */)
{

	ERROR("Number < 0");
	printf("I'm very " CSI BOLD M "bold" CSI RESET M "\n");


	print_8bit_palette();


	return EXIT_SUCCESS;


#if 0
	nat UPDATE_RATE_S = 1;
	m_nat iterations  = 1;

	setvbuf(stdout, NULL, _IOFBF, 0);


	term_altbuff_enter();

	while(--iterations > 0)
	{
		term_clear();

		printf("Remaining %us\n", iterations);
		putchar('\n');

		putchar('\n');

		printf("Test2\n");
		putchar('\n');
		putchar('\n');


/*
 * Network
 * [ ] ssid (“Webpocket”)
 * [ ] address (address, “Disconnected”)

 * CPU
 * [ ] usage (%)
 * [ ] temperature (*C)

 * RAM
 * [ ] usage (%)
 * [ ] used (Gb)
 * [ ] total (Gb)

 * Memory
 * [ ] usage (%)
 * [ ] used (Gb)
 * [ ] total (Gb)

 * Battery
 * [ ] stored (%)
 * [ ] status (“charging”, “discharging”)
 * [ ] time until depleted (time)
 * [ ] time until full (time)

 * Power
 * [ ] source (“socket”, “battery”)
 * [ ] draw (W)
 */


		printf("Press ^C to quit: ");

		fflush(stdout);
		sleep(UPDATE_RATE_S);
	}

	term_altbuff_exit();
	*/
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


/* Operating System
 * [ ] name ("macOS Monterey")
 * [ ] uptime (time) */

string os_name(void)
{
	return "F";
}
