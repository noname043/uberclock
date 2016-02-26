#ifndef _CLOCK_SETTINGS_SCREEN_H_
#define _CLOCK_SETTINGS_SCREEN_H_

#include "screen.h"
#include "numinput.h"

class RTC_DS1307;

class ClockSettingsScreen :
	public Screen
{
public:
	ClockSettingsScreen();

	void init();

	ScreenId update();
	void display();

private:
	void onSwitchedTo();
	void onMessage(RemoteInput::Message message);
	void setFieldsToCurrentTime();
	void adjustClock();

private:
	enum FieldId
	{
		FieldId_Hour,
		FieldId_Minute,
		FieldId_Second,
		FieldId_Day,
		FieldId_Month,
		FieldId_Year,
		FieldId_Total
	};

	FieldId _currentField;
	NumInput *_fields[FieldId_Total];

	NumInput _hourInput;
	NumInput _minuteInput;
	NumInput _secondInput;
	NumInput _dayInput;
	NumInput _monthInput;
	NumInput _yearInput;

	RTC_DS1307 *_clock;
};

#endif