/**
 * A stopwatch class to time the runtime of an algorithms and processes. Uses
 * the standard java method (<code>System.currentTimeMills()</code>) to get the
 * current time in milliseconds since the Unix epoch.
 * 
 * @author Daniël du Preez 
 */
public class Stopwatch
{
	/** One hour worth of milliseconds. */
	private static final long ONE_HOUR = 0x000000000036EE80L;;

	/** The start time of the stopwatch in milliseconds. */
	private long startTime;

	/** The end time of the stopwatch. in milliseconds */
	private long endTime;

	/** The number of laps recorded by the stopwatch. */
	private int laps;

	/**
	 * Sets the start time for the stopwatch by setting the
	 * <code>startTime</code> variable to the current time in milliseconds.
	 */
	public void start()
	{
		startTime = System.currentTimeMillis();
	}

	/**
	 * Sets the end time for the stopwatch by setting the <code>endTime</code>
	 * variable to the current time in milliseconds.
	 */
	public void stop()
	{
		endTime = System.currentTimeMillis();
	}

	/**
	 * Records a new lap by incrementing the <code>laps</code> variable. This
	 * count is used to calculate the mean lap time later.
	 */
	public void lap()
	{
		laps++;
	}

	/**
	 * Calculates the time the stopwatch ran for by calculating the difference
	 * between the start and end times.
	 * 
	 * @return The time the stopwatch ran for in milliseconds.
	 */
	public long getTime()
	{
		return endTime - startTime;
	}

	/**
	 * Calculates the mean time per lap by dividing the total time the stopwatch
	 * ran for by the number of recorded laps.
	 * 
	 * @return The mean lap time in milliseconds.
	 */
	public long getMean()
	{
		return getTime() / laps;
	}

	/**
	 * Generates a String representation of the total time on the stopwatch
	 * using the <code>formatTime</code> method.
	 * 
	 * @return The total time as a String.
	 */
	public String getTimeString()
	{
		return formatTime(getTime());
	}

	/**
	 * Generates a String representation of the mean time interval using the
	 * <code>formatTime</code> method.
	 * 
	 * @return The mean time as a String
	 */
	public String getMeanString()
	{
		return formatTime(getMean());
	}

	/**
	 * Formats the time interval of the stopwatch using the
	 * <code>formatTime</code> method.
	 * 
	 * @return A formated version of the stopwatch's time.
	 */
	@Override
	public String toString()
	{
		return getTimeString();
	}

	/**
	 * Formats a interval of milliseconds into milliseconds, seconds, minutes,
	 * and hours (if applicable) in the form HH:MM:SS:mmm or MM:SS:mmm.
	 * 
	 * @param interval
	 *            The interval in milliseconds.
	 * @return The formated time interval.
	 */
	public static String formatTime(long interval)
	{
		if (interval >= ONE_HOUR)
			return String.format("%1$02d:%2$tM:%2$tS:%2$tL", interval / ONE_HOUR, interval);
		else
			return String.format("%1$tM:%1$tS:%1$tL", interval);
	}
}
