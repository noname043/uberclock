#ifndef _UBERCLOCK_H_
#define _UBERCLOCK_H_

#include <RTClib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "remoteinput.h"
#include "backlight.h"
#include "temperaturesensor.h"
#include "screen.h"
#include "mainscreen.h"
#include "menuscreen.h"
#include "clocksettingsscreen.h"
#include "timer.h"

class Uberclock
{
	static Uberclock *_instance;

public:
	Uberclock();
	static Uberclock *instance() { return _instance; }

	void init();
	void update();
	void display();

	RTC_DS1307 *clock() { return &_clock; }
	Adafruit_PCD8544 *lcdDisplay() { return &_display; }
	RemoteInput *remoteInput() { return &_remoteInput; }
	Backlight *backlight() { return &_backlight; }
	Timer *backlightTimer() { return &_backlightTimer; }
	TemperatureSensor *temperatureSensor() { return &_tempSensor; }

private:
	RTC_DS1307 _clock;
	Adafruit_PCD8544 _display;
	RemoteInput _remoteInput;
	Backlight _backlight;
	Timer _backlightTimer;
	TemperatureSensor _tempSensor;
	Timer _fpsTimer;
	int _frameCount;

	ScreenId _currentScreen;
	ScreenId _nextScreen;
	Screen *_screens[ScreenId_Total];

	MainScreen _mainScreen;
	MenuScreen _menuScreen;
	ClockSettingsScreen _clockSettingsScreen;
};

#endif