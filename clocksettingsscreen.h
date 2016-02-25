#ifndef _CLOCK_SETTINGS_SCREEN_H_
#define _CLOCK_SETTINGS_SCREEN_H_

#include "screen.h"
class ClockSettingsScreen :
	public Screen
{
public:
	ClockSettingsScreen();

	ScreenId update();
	void display();

private:
	void onSwitchedTo();
};

#endif