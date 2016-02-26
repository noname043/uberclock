#ifndef _NUMINPUT_H_
#define _NUMINPUT_H_

#include <WString.h>

class Adafruit_PCD8544;

class NumInput
{
public:
	NumInput(int rangeFrom, int rangeTo, int digitCount);

	int value() const { return _digits.toInt(); }
	bool setValue(int val);
	bool putDigit(int digit);
	bool moveToNextDigit();
	bool moveToPrevDigit();
	bool atEnd() const { return _currentDigit >= _digitCount - 1; }

	void printTo(Adafruit_PCD8544 &display, bool isActive = false);

private:
	int _rangeFrom;
	int _rangeTo;
	int _digitCount;
	String _digits;
	int _currentDigit;
};

#endif

