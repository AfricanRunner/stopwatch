# Stop_Watch

I often want to measure the execution time of programs written in various languages. However, not only does each language have its own method for measuring time, but they lack consistent formats for displaying the execution time. My goal for this repository is to keep track of some simple and consistent stopwatch programs that wrap each language's custom timing protocols and displays the time in a consistent format. 

All the stopwatches format the data in the same `MM:SS:mmm` or `HH:MM:SS:mmm` format (the hour is only displayed if the time interval is larger than an hour).

Depending on the language, the stopwatch may be a structure (c, c++) or an object (java). However, all the functions/methods are formatted similarly and accomplish the same thing.

For each stopwatch there is a play, lap, stop, and print function/method.
- play: Sets the lap counter to one and records the current time.
- lap: Increments the lap counter.
- stop: Records the current time.
- print: Exact function/method depends on the language but all the stopwatches return the time interval in the same format.

## Example Use Cases

**C**

```c
stopwatch sw;
START(sw);

foo();

STOP(sw);
PRINT(sw);
```

**C++**

```cpp
sw::stopwatch sw;
sw.start();

foo();

sw.stop();
std::cout << sw << std::endl;
```

**Java**

```java
Stopwatch sw = new Stopwatch();
sw.start();

foo();

sw.stop();
System.out.println(sw);
```

