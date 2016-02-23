#ifndef _REMOTE_INPUT_h
#define _REMOTE_INPUT_h

#include <IRremote.h>

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
};

#endif

