#ifndef _TIMER_h
#define _TIMER_h

// Stores time in ms.
class Timer
{
public:
	Timer() :
		_interval(0),
		_started(0)
	{}

	Timer(unsigned long interval) :
		_interval(interval),
		_started(0)
	{}

	void setInterval(unsigned long interval) { _interval = interval; }
	bool isFinished() const { return millis() >= _started + _interval; }
	void start() { _started = millis(); }

private:
	unsigned long _interval;
	unsigned long _started;
};

#endif

