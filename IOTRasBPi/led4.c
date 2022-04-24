#include <stdio.h>
#include <wiringPi.h>

#define LedGreenPin	5
#define LedRedPin	4

int main(void)
{
	if(wiringPiSetupGpio() == -1)
		return 1;

	pinMode(LedGreenPin, OUTPUT);
	pinMode(LedRedPin, OUTPUT);
	int i;
	for (i = 0; i < 5; i++){
		digitalWrite(LedGreenPin, HIGH);
		delay(500);
		digitalWrite(LedGreenPin, LOW);
		delay(500);
		digitalWrite(LedRedPin, HIGH);
		delay(500);
		digitalWrite(LedRedPin, LOW);
		delay(500);
	}
	return 0;
}
