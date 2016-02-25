#include "menu.h"
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "app.h"

Menu::Menu(int optCount):
_currentIndex(0),
_optionsCount(optCount)
{
	_options = new MenuOption[optCount];
}

Menu::~Menu()
{
	delete[] _options;
}

void Menu::init()
{
	Uberclock *app = Uberclock::instance();
	_display = app->lcdDisplay();
}

void Menu::moveUp()
{
	if (_currentIndex > 0)
		--_currentIndex;
}

void Menu::moveDown()
{
	if (_currentIndex < _optionsCount - 1)
		++_currentIndex;
}

void Menu::display()
{
	for (int i = 0; i < _optionsCount; ++i)
	{
		if (i == _currentIndex)
			_display->setTextColor(WHITE, BLACK);
		else
			_display->setTextColor(BLACK, WHITE);
		_display->println(_options[i].name);
	}
	_display->setTextColor(BLACK, WHITE);
}

MenuOption *Menu::option(int index)
{
	if (index < 0 || index >= _optionsCount)
		return 0;
	return &_options[index];
}