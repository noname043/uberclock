#include "clocksettingsscreen.h"
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#include "app.h"

ClockSettingsScreen::ClockSettingsScreen():
_currentField(FieldId_Hour),
_hourInput(0, 23, 2),
_minuteInput(0, 59, 2),
_secondInput(0, 59, 2),
_dayInput(1, 31, 2),
_monthInput(1, 12, 2),
_yearInput(2000, 9999, 4)
{
	_fields[FieldId_Hour] = &_hourInput;
	_fields[FieldId_Minute] = &_minuteInput;
	_fields[FieldId_Second] = &_secondInput;
	_fields[FieldId_Day] = &_dayInput;
	_fields[FieldId_Month] = &_monthInput;
	_fields[FieldId_Year] = &_yearInput;
}

void ClockSettingsScreen::init()
{
	Screen::init();
	Uberclock *app = Uberclock::instance();
	_clock = app->clock();
}

ScreenId ClockSettingsScreen::update()
{
	ScreenId tmp = Screen::update();
	return tmp;
}

void ClockSettingsScreen::display()
{
	for (int i = FieldId_Hour; i <= FieldId_Second; ++i)
	{
		if (i > FieldId_Hour)
			_display->print(':');
		_fields[i]->printTo(*_display, i == _currentField);
	}
	_display->println();
	for (int i = FieldId_Day; i <= FieldId_Year; ++i)
	{
		if (i > FieldId_Day)
			_display->print('.');
		_fields[i]->printTo(*_display, i == _currentField);
	}
}

void ClockSettingsScreen::onSwitchedTo()
{
	_nextScreen = ScreenId_ClockSettings;
	setFieldsToCurrentTime();
}

void ClockSettingsScreen::onMessage(RemoteInput::Message message)
{
	Screen::onMessage(message);

	switch (message)
	{
	case RemoteInput::KeyReturn:
		_nextScreen = ScreenId_Menu;
		break;
	case RemoteInput::KeyEnter:
		adjustClock();
		_nextScreen = ScreenId_Main;
		break;
	case RemoteInput::KeyLeft:
		if (!_fields[_currentField]->moveToPrevDigit() && _currentField > FieldId_Hour)
			_currentField = (FieldId)(_currentField - 1);
		break;
	case RemoteInput::KeyRight:
		if (!_fields[_currentField]->moveToNextDigit() && _currentField < FieldId_Year)
			_currentField = (FieldId)(_currentField + 1);
	case RemoteInput::Key0:
	case RemoteInput::Key1:
	case RemoteInput::Key2:
	case RemoteInput::Key3:
	case RemoteInput::Key4:
	case RemoteInput::Key5:
	case RemoteInput::Key6:
	case RemoteInput::Key7:
	case RemoteInput::Key8:
	case RemoteInput::Key9:
		if (_fields[_currentField]->putDigit(message - RemoteInput::Key0) &&
			!_fields[_currentField]->moveToNextDigit())
		{
			if (_currentField < FieldId_Total - 1)
				_currentField = (FieldId)(_currentField + 1);
		}
		break;
	default:
		break;
	}
}

void ClockSettingsScreen::setFieldsToCurrentTime()
{
	DateTime now = _clock->now();
	_hourInput.setValue(now.hour());
	_minuteInput.setValue(now.minute());
	_secondInput.setValue(now.second());
	_dayInput.setValue(now.day());
	_monthInput.setValue(now.month());
	_yearInput.setValue(now.year());
}

void ClockSettingsScreen::adjustClock()
{
	_clock->adjust(DateTime(_yearInput.value(),
		_monthInput.value(),
		_dayInput.value(),
		_hourInput.value(),
		_minuteInput.value(),
		_secondInput.value()));
}