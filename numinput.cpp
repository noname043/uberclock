#include "numinput.h"
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

NumInput::NumInput(int rangeFrom, int rangeTo, int digitCount) :
_rangeFrom(rangeFrom),
_rangeTo(rangeTo),
_digitCount(digitCount),
_digits(),
_currentDigit(0)
{
	_digits.reserve(digitCount);
	for (int i = 0; i < _digitCount; ++i)
		_digits += '0';
}

bool NumInput::putDigit(int digit)
{
	if (digit < 0 || digit > 9)
		return false;
	
	char tmp = _digits[_currentDigit];
	_digits[_currentDigit] = ((char)digit) + '0';
	int val = _digits.toInt();
	if (val < _rangeFrom || val > _rangeTo)
	{
		_digits[_currentDigit] = tmp;
		return false;
	}

	return true;
}

bool NumInput::moveToNextDigit()
{
	if (atEnd())
		return false;
	++_currentDigit;
	return true;
}

bool NumInput::moveToPrevDigit()
{
	if (_currentDigit == 0)
		return false;
	--_currentDigit;
	return true;
}

bool NumInput::setValue(int val)
{
	if (val < _rangeFrom || val > _rangeTo)
		return false;
	
	for (int i = _digitCount - 1; i >= 0; --i)
	{
		_digits[i] = '0' + (val % 10);
		val /= 10;
	}
	return true;
}

void NumInput::printTo(Adafruit_PCD8544 &display, bool isActive)
{
	for (int i = 0; i < _digitCount; ++i)
	{
		if (isActive && i == _currentDigit)
			display.setTextColor(WHITE, BLACK);
		display.print(_digits[i]);
		display.setTextColor(BLACK);
	}
}