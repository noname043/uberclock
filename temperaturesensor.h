#ifndef _TEMPERATURESENSOR_H_
#define _TEMPERATURESENSOR_H_

#include "timer.h"

class TemperatureSensor
{
public:
	TemperatureSensor(int pin);

	void update();

	double reading() const { return _reading; }

private:
	Timer _timer;
	int _pin;
	double _reading;
	double _sum;
	int _readingCount;
};

#endif