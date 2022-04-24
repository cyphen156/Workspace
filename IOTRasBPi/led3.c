//LED 한 개 사용자로부터 입력 받은 숫자만큼 깜빡이기
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
