#include "sgr.h"

void print_8bit_palette(void)
{
	int x, y, rx, ry;

	for(y = 0; y < 3; ++y)
	{
		for(ry = 0; ry < 6; ++ry)
		{
			for(x = 0; x < 2; ++x)
			{
				for(rx = 0; rx < 6; ++rx)
				{
					int code = 16 + 18 * x + rx + 6 * y + 36 * ry;

					if(x)
						printf(CSI FG_BLACK M);
					else
						printf(CSI FG_DEFAULT M);

					printf(CSI BG_PAL() "%d" M " %3.d ", code, code);
				}

				if(!x) printf(CSI RESET M "\t");
			}
			printf(CSI RESET M "\n");
		}
		printf(CSI RESET M "\n");
	}
}
