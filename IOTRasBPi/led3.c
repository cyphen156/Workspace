#include <stdio.h>
#include <wiringPi.h>
#define LED	4
int main(void)
{
	if (wiringPiSetupGpio() == -1)
		return 1;
	pinMode(LED, OUTPUT);
	int a;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		digitalWrite(LED, HIGH);
		delay(500);
		digitalWrite(LED, LOW);
		delay(500);
	}
	return 0;
}
