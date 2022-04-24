#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define LedGreenPin	5
#define LedRedPin	4

int main(void)
{
	if(wiringPiSetupGpio() == -1)
		return 1;

	pinMode(LedGreenPin, OUTPUT);
	pinMode(LedRedPin, OUTPUT);
	softPwmCreate(LedGreenPin, 0, 100);
	softPwmCreate(LedRedPin, 0, 100);
	int i, j;
	for (int k = 0; k < 10; k++) {
		for (i = 0; i < 100; i++){
			softPwmWrite(LedGreenPin, i);
			softPwmWrite(LedRedPin, i);
			delay(50);
		}
		for (j = 100; j > 0; j--){
			softPwmWrite(LedGreenPin, j);
			softPwmWrite(LedRedPin, j);
			delay(50);
		}
		delay(50);
	}
	return 0;
}
