#include "remoteinput.h"

RemoteInput::RemoteInput(int pin):
_receiver(pin),
_debounceTimer(500)
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
		if (_debounceTimer.isFinished())
		{
			_debounceTimer.start();
			message = translate(_results.value);
			if (message == None)
			{
				Serial.print("RemoteInput::read() - value: ");
				Serial.println(_results.value, HEX);
			}
			_receiver.resume();
		}
	}
	return message;
}

void RemoteInput::setBlinkLed(bool blinkLed)
{
	_receiver.blink13(blinkLed);
}

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