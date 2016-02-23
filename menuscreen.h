#ifndef _MENU_SCREEN_H_
#define _MENU_SCREEN_H_

#include "screen.h"

class MenuScreen : public Screen
{
public:
	MenuScreen();

	ScreenId update();
	void display();
};

#endif