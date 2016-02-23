#include "remoteinput.h"

RemoteInput::RemoteInput(int pin):
_receiver(pin)
{}

void RemoteInput::init()
{
	_receiver.enableIRIn();
}

RemoteInput::Message RemoteInput::read()
{
	Message message = None;
	if (_receiver.decode(&_results))
	{
		message = translate(_results.value);
		if (message == None)
		{
			Serial.print("RemoteInput::read() - value: ");
			Serial.println(_results.value, HEX);
		}
		_receiver.resume();
	}
	return message;
}

void RemoteInput::setBlinkLed(bool blinkLed)
{
	_receiver.blink13(blinkLed);
}

enum RemoteCode
{
	Power = 0xFF28D7,
	OpenClose = 0xFF08F7,
	Enter = 0xFFE01F,
	Return = 0xFF7A85,
	Menu = 0xFFA25D,
	Up = 0xFF609F,
	Down = 0xFF22DD,
	Left = 0xFFFFFF, // TODO
	Right = 0xFFFFFE, // TODO
	Num0 = 0xFF12ED,
	Num1 = 0xFFB847,
	Num2 = 0xFFF807,
	Num3 = 0xFFF867,
	Num4 = 0xFFD827,
	Num5 = 0xFF8877,
	Num6 = 0xFF48B7,
	Num7 = 0xFFE817,
	Num8 = 0xFF9A65,
	Num9 = 0xFF52AD
};

RemoteInput::Message RemoteInput::translate(unsigned long reading)
{
	switch (reading)
	{
	case Power: return BacklightOnce;
	case OpenClose: return BacklightOnOff;
	case Enter: return KeyEnter;
	case Return: return KeyReturn;
	case Menu: return KeyMenu;
	case Up: return KeyUp;
	case Down: return KeyDown;
	case Left: return KeyLeft;
	case Right: return KeyRight;
	case Num0: return Key0;
	case Num1: return Key1;
	case Num2: return Key2;
	case Num3: return Key3;
	case Num4: return Key4;
	case Num5: return Key5;
	case Num6: return Key6;
	case Num7: return Key7;
	case Num8: return Key8;
	case Num9: return Key9;
	default: return None;
	}
}