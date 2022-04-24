#include <stdio.h>
#include <wiringPi.h>
#define KEYPAD_PB	9
int eventCounter = 0;
void myInterrupt(void){
	eventCounter++;
}

int main(void){
	if(wiringPiSetupGpio() < 0)
		return 1;
	if(wiringPiISR(KEYPAD_PB, INT_EDGE_FALLING, &myInterrupt) <0)
		return 1;
	while(1){
		printf("%d\n", eventCounter);
		eventCounter = 0;
		delay(1000);
	}
	return 0;
}
