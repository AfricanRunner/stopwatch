
#ifndef STOPWATCH_H
#define STOPWATCH_H

#include "time.h"

#define START(n) sw_start(&(n))
#define STOP(n) sw_stop(&(n))
#define LAP(n) sw_lap(&(n))

#define PRINT(n) sw_print_total(&(n))

typedef struct 
{
	clock_t start_t;
	clock_t end_t;
	int laps;
} stopwatch;

extern void sw_start(stopwatch* sw);
extern void sw_lap(stopwatch* sw);
extern void sw_stop(stopwatch* sw);

extern clock_t sw_get_total_t(stopwatch* sw);
extern clock_t sw_get_mean_t(stopwatch* sw);

extern void sw_print_total(stopwatch* sw);
extern void sw_print_mean(stopwatch* sw);

extern void sw_print(clock_t time);

#endif /* STOPWATCH_H */
