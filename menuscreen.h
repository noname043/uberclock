#ifndef _MENU_SCREEN_H_
#define _MENU_SCREEN_H_

#include "screen.h"
#include "menu.h"

class MenuScreen : public Screen
{
public:
	MenuScreen();

	void init();

	ScreenId update();
	void display();

	void onMessage(RemoteInput::Message message);

private:
	Menu _menu;
	ScreenId _nextScreen;
};

#endif