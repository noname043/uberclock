#ifndef _REMOTE_INPUT_h
#define _REMOTE_INPUT_h

#include <IRremote.h>
#include "timer.h"

class RemoteInput
{
public:
	enum Message
	{
		None,
		BacklightOnOff,
		BacklightOnce,
		KeySetup,
		KeyReturn,
		KeyMenu,
		KeyUp,
		KeyDown,
		KeyLeft,
		KeyRight,
		KeyEnter,
		Key0,
		Key1,
		Key2,
		Key3,
		Key4,
		Key5,
		Key6,
		Key7,
		Key8,
		Key9
	};

	RemoteInput(int pin);

	void init();
	Message read();
	void setBlinkLed(bool blinkLed);

private:
	Message translate(unsigned long reading);

private:
	IRrecv _receiver;
	decode_results _results;
	Timer _debounceTimer;

	enum RemoteCode
	{
		Power = 0xFF28D7,
		OpenClose = 0xFF08F7,
		Enter = 0xFFE01F,
		Return = 0xFF7A85,
		Menu = 0xFFA25D,
		Up = 0xFF609F,
		Down = 0xFF22DD,
		Left = 0xFFE21D,
		Right = 0xFF02FD,
		Num0 = 0xFF12ED,
		Num1 = 0xFFB847,
		Num2 = 0xFFF807,
		Num3 = 0xFF9867,
		Num4 = 0xFFD827,
		Num5 = 0xFF8877,
		Num6 = 0xFF48B7,
		Num7 = 0xFFE817,
		Num8 = 0xFF9A65,
		Num9 = 0xFF52AD
	};
};

#endif

