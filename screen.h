#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "remoteinput.h"
#include "timer.h"

class Adafruit_PCD8544;
class Backlight;

enum ScreenId
{
	ScreenId_None = -1,
	ScreenId_Main,
	ScreenId_Menu,
	ScreenId_ClockSettings,
	ScreenId_Total
};

class Screen
{
public:
	Screen();
	virtual ~Screen() {}

	virtual void init();
	virtual ScreenId update();
	virtual void display() = 0;
	virtual void onSwitchedTo() = 0;

protected:
	virtual void onMessage(RemoteInput::Message message);

protected:
	ScreenId _nextScreen;

	Adafruit_PCD8544 *_display;
	RemoteInput::Message _lastMessage;

private:
	RemoteInput *_remoteInput;
	Backlight *_backlight;
	Timer *_backlightTimer;
};

#endif