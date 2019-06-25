
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

clock_t sw_get_total_t(stopwatch* sw)
{
	return sw->end_t - sw->start_t;
}

clock_t sw_get_mean_t(stopwatch* sw)
{
	return sw_get_total_t(sw) / sw->laps;
}

void sw_print_total(stopwatch* sw)
{
	sw_print(sw_get_total_t(sw));
}

void sw_print_mean(stopwatch* sw)
{
	sw_print(sw_get_mean_t(sw));
}

void sw_print(clock_t time)
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

