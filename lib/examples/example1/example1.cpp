#include "Arduino.h"

void setup()
{
	Serial1.begin(115200);
	Serial1.println("Hello World!");
}

void loop()
{
	delay(100);

	Serial1.println(micros());
	delay(1000);
}
