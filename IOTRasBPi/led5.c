//LED 점점 밝아지기
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
	int i;
	for (i = 0; i < 100; i++){
		softPwmWrite(LedGreenPin, i);
		softPwmWrite(LedRedPin, i);
		delay(50);
	}
	softPwmWrite(LedGreenPin, 0);
	softPwmWrite(LedRedPin, 0);
	delay(50);
	return 0;
}
