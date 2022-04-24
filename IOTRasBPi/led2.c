//LED 한 개 5 번 깜빡이기
#include <stdio.h>
#include <wiringPi.h>
#define LED	4
int main(void)
{
	if (wiringPiSetupGpio() == -1)
		return 1;
	pinMode(LED, OUTPUT);

	for (int i = 0; i < 5; i++) {
		digitalWrite(LED, HIGH);
		delay(500);
		digitalWrite(LED, LOW);
		delay(500);
	}
	return 0;
}
