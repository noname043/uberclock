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
}

ScreenId Screen::update()
{
	RemoteInput::Message message = _remoteInput->read();
	if (message != RemoteInput::None)
		onMessage(message);

	return ScreenId_None;
}

void Screen::onMessage(RemoteInput::Message message)
{
	_lastMessage = message;
	if (message == RemoteInput::BacklightOnOff)
	{
		_backlight->setIsOn(!_backlight->isOn());
	}
	else if (message == RemoteInput::BacklightOnce)
	{
		Serial.println("not supported yet");
	}
}