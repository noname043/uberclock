#include "mainscreen.h"
#include "app.h"

MainScreen::MainScreen()
{
}

void MainScreen::init()
{
	Screen::init();
	Uberclock *app = Uberclock::instance();
	_clock = app->clock();
	_temperatureSensor = app->temperatureSensor();
}

ScreenId MainScreen::update()
{
	Screen::update();

	_temperatureSensor->update();

	_currentTime = _clock->now();
	return ScreenId_Main;
}

void MainScreen::display()
{
	printTime();
	printDate();
	printTemperature();
}

void MainScreen::printTime()
{
	_display->setTextSize(2);
	printDTElement(_currentTime.hour());
	_display->print(':');
	printDTElement(_currentTime.minute());

	_display->setTextSize(1);
	_display->setCursor(_display->getCursorX(), _display->getCursorY() + 7);
	_display->print(':');
	printDTElement(_currentTime.second());
	_display->println();
}

void MainScreen::printDate()
{
	printDTElement(_currentTime.day());
	_display->print('.');
	printDTElement(_currentTime.month());
	_display->print('.');
	_display->println(_currentTime.year());
}

void MainScreen::printTemperature()
{
	_display->print(_temperatureSensor->reading());
	_display->println("*C");
}

void MainScreen::printDTElement(unsigned char x)
{
	if (x < 10)
		_display->print('0');
	_display->print(x);
}

void MainScreen::onMessage(RemoteInput::Message message)
{
	Screen::onMessage(message);
}