#include <stdio.h>
#include <wiringPi.h>	//얘가 하는거는?
#define LED	4
int main(void)
{
	if (wiringPiSetupGpio() == -1)
		return 1;
	pinMode(LED, OUTPUT);	//빈칸뚫기 OUTPUT
digitalWrite(LED, HIGH);	//함수 뭐하는지 맞추기, 전달 인자 채우기
delay(500);
digitalWrite(LED, LOW);
delay(500);

return 0;
}
