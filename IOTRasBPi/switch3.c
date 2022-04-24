#include <wiringPi.h>
#include <stdio.h>
#define LED_PIN		4
#define KEYPAD_PB	9
#define KEYPAD_ON	0
#define KEYPAD_OFF	1

int keypad_status = KEYPAD_OFF;

void keyPadISR(void) {
	keypad_status = keypad_status ^ 1;
}

 int main(void) {
    if(wiringPiSetupGpio() == -1)
        return 1;
    pinMode(LED_PIN, OUTPUT);
    pinMode(KEYPAD_PB, INPUT);

    if(wiringPiISR(KEYPAD_PB, INT_EDGE_FALLING, &keyPadISR) < 0)
		return 1;

	digitalWrite(LED_PIN, LOW);
	
	while (1) {
		if(keypad_status == KEYPAD_ON) {
			printf("aa\n");
			digitalWrite(LED_PIN, HIGH);
		}else {
			printf("bb\n");
			digitalWrite(LED_PIN, LOW);
		}
	}
	return 0;
 }
