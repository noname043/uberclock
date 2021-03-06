#include "menuscreen.h"

MenuScreen::MenuScreen():
_menu(2)
{
	_menu.option(0)->id = 0;
	_menu.option(0)->name = "time settings";
	_menu.option(1)->id = 1;
	_menu.option(1)->name = "set alarm";

	_nextScreen = ScreenId_Menu;
}

void MenuScreen::init()
{
	Screen::init();
	_menu.init();
}

ScreenId MenuScreen::update()
{
	return Screen::update();
}

void MenuScreen::display()
{
	_menu.display();
}

void MenuScreen::onMessage(RemoteInput::Message message)
{
	Screen::onMessage(message);

	switch (message)
	{
	case RemoteInput::KeyUp:
		_menu.moveUp();
		break;
	case RemoteInput::KeyDown:
		_menu.moveDown();
		break;
	case RemoteInput::KeyReturn:
		_nextScreen = ScreenId_Main;
		break;
	case RemoteInput::KeyEnter:
		if (_menu.currentOptionId() == 0)
			_nextScreen = ScreenId_ClockSettings;
		else
			Serial.println("not implemented yet");
		break;
	default:
		break;
	}
}

void MenuScreen::onSwitchedTo()
{
	_nextScreen = ScreenId_Menu;
}