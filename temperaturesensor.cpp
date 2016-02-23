#include "temperaturesensor.h"
#include <Arduino.h>
#include "config.h"

TemperatureSensor::TemperatureSensor(int pin) :
_timer(1000 / TEMPERATURE_SENSOR_RPS),
_pin(pin),
_reading(0),
_readingCount(0)
{
	pinMode(pin, INPUT);
}

void TemperatureSensor::update()
{
	if (_timer.isFinished())
	{
		_timer.start();
		_sum += analogRead(_pin) * 500.0 / 1024.0;
		++_readingCount;

		if (_readingCount >= TEMPERATURE_SENSOR_RPS)
		{
			_reading = _sum / TEMPERATURE_SENSOR_RPS;
			_sum = 0;
			_readingCount = 0;
		}
	}
}