#include "app.h"
#include "config.h"

Uberclock *Uberclock::_instance = 0;

Uberclock::Uberclock():
_display(3, 4, 5, 6, 7),
_remoteInput(REMOTE_PIN),
_backlight(DISPLAY_BACKLIGHT_PIN),
_backlightTimer(DISPLAY_BACKLIGHT_DURATION),
_tempSensor(TEMPERATURE_SENSOR_PIN),
_currentScreen(ScreenId_Main),
_nextScreen(ScreenId_Main),
_fpsTimer(1000),
_frameCount(0)
{
	if (!_instance)
		_instance = this;
}

void Uberclock::init()
{
	_clock.begin();
	_display.begin();
	_remoteInput.init();
	_remoteInput.setBlinkLed(true);

	_screens[ScreenId_Main] = &_mainScreen;
	_screens[ScreenId_Menu] = &_menuScreen;
	_screens[ScreenId_ClockSettings] = &_clockSettingsScreen;

	for (int i = 0; i < ScreenId_Total; ++i)
		_screens[i]->init();

	_backlight.setIsOn(true);

	_fpsTimer.start();
}

void Uberclock::update()
{
	if (_currentScreen != _nextScreen)
	{
		_screens[_nextScreen]->onSwitchedTo();
		_currentScreen = _nextScreen;
	}
	_nextScreen = _screens[_currentScreen]->update();
}

void Uberclock::display()
{
	_display.clearDisplay();
	_screens[_currentScreen]->display();
	_display.display();

	++_frameCount;
	if (_fpsTimer.isFinished())
	{
		_fpsTimer.start();
		Serial.print("FPS: ");
		Serial.println(_frameCount);
		_frameCount = 0;
	}
}