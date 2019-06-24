
#ifndef STOPWATCH_H
#define STOPWATCH_H

#include "time.h"

#define START(n) sw_start(&(n))
#define STOP(n) sw_stop(&(n))
#define LAP(n) sw_lap(&(n))

#define PRINT(n) sw_print(&(n))

typedef struct 
{
	clock_t start_t;
	clock_t end_t;
	int laps;
} stopwatch;

extern void sw_start(stopwatch* sw);
extern void sw_lap(stopwatch* sw);
extern void sw_stop(stopwatch* sw);

extern void sw_print(stopwatch* sw);

#endif /* STOPWATCH_H */
