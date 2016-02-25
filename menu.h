#ifndef _MENU_
#define _MENU_

class Adafruit_PCD8544;

class MenuOption
{
public:
	int id;
	const char *name;
};

class Menu
{
public:
	Menu(int optCount);
	~Menu();

	void init();

	void moveUp();
	void moveDown();

	void display();

	MenuOption *option(int index);
	int currentOptionId() const { return _options[_currentIndex].id; }

private:
	MenuOption *_options;
	int _optionsCount;
	int _currentIndex;

	Adafruit_PCD8544 *_display;
};

#endif

