
#include <iostream>

#include "stopwatch.h"

using namespace sw;

int main()
{
	stopwatch sw;
	sw.start();

	// A time consuming task.

	sw.stop();
	std::cout << sw << std::endl;

	return 1;
}
