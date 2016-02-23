#include "backlight.h"
#include <Arduino.h>

Backlight::Backlight(int pin) :
_pin(pin),
_isOn(false),
_isAutomatic(false)
{
	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
}

void Backlight::setIsOn(bool isOn)
{
	digitalWrite(_pin, isOn ? HIGH : LOW);
	_isOn = isOn;
}
