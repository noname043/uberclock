#include "clocksettingsscreen.h"


ClockSettingsScreen::ClockSettingsScreen()
{
}

ScreenId ClockSettingsScreen::update()
{
	ScreenId tmp = Screen::update();
	return tmp;
}

void ClockSettingsScreen::display()
{

}

void ClockSettingsScreen::onSwitchedTo()
{
	_nextScreen = ScreenId_Main;//ScreenId_ClockSettings;
}