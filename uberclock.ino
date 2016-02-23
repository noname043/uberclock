#include "app.h"

Uberclock uberclock;

void setup()
{
	Serial.begin(9600);
	uberclock.init();
}

void loop()
{
	uberclock.update();
	uberclock.display();
}
