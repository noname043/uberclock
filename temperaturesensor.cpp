#include "temperaturesensor.h"
#include <Arduino.h>

TemperatureSensor::TemperatureSensor(int pin) :
_pin(pin)
{
	pinMode(pin, INPUT);
}

float TemperatureSensor::reading()
{
	return analogRead(_pin) * 500.0 / 1024.0;
}