#ifndef _BACKLIGHT_H_
#define _BACKLIGHT_H_

class Backlight
{
public:
	Backlight(int pin);

	bool isOn() const { return _isOn; }
	void setIsOn(bool isOn);

	bool isAutomatic() const { return _isAutomatic; }
	void setIsAutomatic(bool isAutomatic) { _isAutomatic = isAutomatic; }

private:
	int _pin;
	bool _isOn;
	bool _isAutomatic;
};

#endif