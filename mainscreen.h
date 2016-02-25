#ifndef _MAIN_SCREEN_H_
#define _MAIN_SCREEN_H_

#include "screen.h"
#include <RTClib.h>

class TemperatureSensor;

class MainScreen : public Screen
{
public:
	MainScreen();

	void init();
	ScreenId update();
	void display();

private:
	void printTime();
	void printDate();
	void printTemperature();
	void printDTElement(unsigned char x);
	void onMessage(RemoteInput::Message message);
	void onSwitchedTo();

private:
	RTC_DS1307 *_clock;
	DateTime _currentTime;
	TemperatureSensor *_temperatureSensor;
};

#endif