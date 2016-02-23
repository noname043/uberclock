#include "screen.h"
#include "app.h"

Screen::Screen():
_lastMessage(RemoteInput::None)
{
}

void Screen::init()
{
	Uberclock *app = Uberclock::instance();
	_display = app->lcdDisplay();
	_remoteInput = app->remoteInput();
	_backlight = app->backlight();
	_backlightTimer = app->backlightTimer();
}

ScreenId Screen::update()
{
	RemoteInput::Message message = _remoteInput->read();
	if (message != RemoteInput::None)
		onMessage(message);

	if (_backlight->isAutomatic() && _backlight->isOn() && _backlightTimer->isFinished())
	{
		_backlight->setIsOn(false);
		_backlight->setIsAutomatic(false);
	}

	return ScreenId_None;
}

void Screen::onMessage(RemoteInput::Message message)
{
	_lastMessage = message;
	if (message == RemoteInput::BacklightOnOff)
	{
		_backlight->setIsOn(!_backlight->isOn());
		_backlight->setIsAutomatic(false);
	}
	else if (message == RemoteInput::BacklightOnce)
	{
		_backlight->setIsOn(true);
		_backlight->setIsAutomatic(true);
		_backlightTimer->start();
	}
}