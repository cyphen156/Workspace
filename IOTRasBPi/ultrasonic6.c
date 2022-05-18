#include <softTone.h>
#include <stdio.h>
#include <wiringPi.h>
#define Trigger 4
#define Echo 17
#define Buzzer 11

#define LED_PIN_1 6
#define LED_PIN_2 12
#define LED_PIN_3 13
#define LED_PIN_4 16
#define LED_PIN_5 19
#define LED_PIN_6 20
#define LED_PIN_7 26
#define LED_PIN_8 21

#define MAX_LED_NUM 8

const int LedPinTable[8] = {
LED_PIN_1, LED_PIN_2, LED_PIN_3, LED_PIN_4,
LED_PIN_8, LED_PIN_7, LED_PIN_6, LED_PIN_5
};
int scales[] = {523, 587, 659, 698, 784, 880, 987, 1046};
//do(0), re(1), mi(2), fa(3), sol(4), ra(5), si(6), do(7)
float getDistance(void)
{
	float fDistance;
	int nStartTime, nEndTime;
	digitalWrite(Trigger, LOW);
	delayMicroseconds(2);
	digitalWrite(Trigger, HIGH);
	delayMicroseconds(10);
	digitalWrite(Trigger, LOW);
	while(digitalRead(Echo) == LOW);
	nStartTime = micros();
	while(digitalRead(Echo) == HIGH);
	nEndTime = micros();
	fDistance = (nEndTime - nStartTime) / 58.;
	return fDistance;
}
int main(void){
	if(wiringPiSetupGpio() == -1) return 1;
	pinMode(Trigger, OUTPUT);
	pinMode(Echo, INPUT);
	softToneCreate(Buzzer);
	int i;
	for(i = 0; i < MAX_LED_NUM; i++){
	pinMode(LedPinTable[i], OUTPUT);
	digitalWrite(LedPinTable[i], LOW);
	}
	float fDistance = 0;
	while(1){
	if(digitalRead(Echo) == LOW){
	fDistance = getDistance();
	}else{
	pinMode(Echo, OUTPUT);
	digitalWrite(Echo, LOW);
	pinMode(Echo, INPUT);
	}
	printf("Distance : %.2fcm\n", fDistance);
	int cnt = 3;
	int index = 8;
	if(fDistance > 0 && fDistance <= cnt * 1){
		index = 0;
	}else if(fDistance > cnt * 1 && fDistance <= cnt * 2){
		index = 1;
	}else if(fDistance > cnt * 2 && fDistance <= cnt * 3){
		index = 2;
	}else if(fDistance > cnt * 3 && fDistance <= cnt * 4){
		index = 3;
	}else if(fDistance > cnt * 4 && fDistance <= cnt * 5){
		index = 4;
	}else if(fDistance > cnt * 5 && fDistance <= cnt * 6){
		index = 5;
	}else if(fDistance > cnt * 6 && fDistance <= cnt * 7){
		index = 6;
	}else if(fDistance > cnt * 7 && fDistance <= cnt * 8){
		index = 7;
	}else{
		index = 8; 
	for(i = 0; i < MAX_LED_NUM; i++)
			softToneWrite(Buzzer, 0);
			digitalWrite(LedPinTable[i], LOW);
		}
		if(index < 8){
			softToneWrite(Buzzer, scales[index]);
			digitalWrite(LedPinTable[index], HIGH); 
			delay(200);
		}	
		delay(200);
	}
	return 0; 
}