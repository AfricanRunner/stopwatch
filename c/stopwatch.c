
#include "stopwatch.h"

#include "stdio.h"

void sw_start(stopwatch* sw)
{
	sw->laps = 1;
	sw->start_t = clock();
}

void sw_lap(stopwatch* sw)
{
	sw->laps++;
}

void sw_stop(stopwatch* sw)
{
	sw->end_t = clock();
}

void print(clock_t time)
{
	unsigned long ms = ((time * 1000) / CLOCKS_PER_SEC) % 1000;
	unsigned long s = (time / CLOCKS_PER_SEC) % 60;
	unsigned long m = (time / (CLOCKS_PER_SEC * 60)) % 60;
	unsigned long h = time / ((unsigned long)CLOCKS_PER_SEC * 60 * 60);

	if(h > 1)
		printf("%02lu:%02lu:%02lu:%03lu", h, m, s, ms);
	else
		printf("%02lu:%02lu:%03lu", m, s, ms);
}

void sw_print(stopwatch* sw)
{
	clock_t time = (sw->end_t - sw->start_t);

	printf("Total Time: ");
	print(time);
	printf("\n");

	if(sw->laps != 1)
	{
		time /= sw->laps;

		printf("Average Lap: ");
		print(time);
		printf("\n");
	}
}

