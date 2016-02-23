#ifndef _BACKLIGHT_H_
#define _BACKLIGHT_H_

class Backlight
{
public:
	Backlight(int pin);

	bool isOn() const { return _isOn; }
	void setIsOn(bool isOn);

private:
	int _pin;
	bool _isOn;
};

#endif