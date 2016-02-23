#ifndef _TEMPERATURESENSOR_H_
#define _TEMPERATURESENSOR_H_

class TemperatureSensor
{
public:
	TemperatureSensor(int pin);

	float reading();

private:
	int _pin;
};

#endif