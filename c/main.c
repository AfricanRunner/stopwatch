
#include "stdio.h"

#include "stopwatch.h"

int main()
{
	stopwatch sw;
	START(sw);

	// Something that takes time.

	STOP(sw);
	PRINT(sw);

	return 0;
}
