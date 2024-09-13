#include "I2CScanner.h"

I2CScanner scanner;

void setup() 
{
	Serial.begin(115200);
	while (!Serial) {};

	scanner.Init();
}

void loop() 
{
	scanner.Scan();
	delay(5000);
}
