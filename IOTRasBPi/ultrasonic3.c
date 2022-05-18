#include <softTone.h>
#include <stdio.h>
#include <wiringPi.h>
#define Trigger	4
#define Echo	17
#define Buzzer	11
int scales[] = {523, 587, 659, 698, 784, 880, 987, 1046};

float getDistance (void) {
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

	fDistance = (nEndTime - nStartTime) / 58.0;
	return fDistance;
}

int main(void) {
	if(wiringPiSetupGpio()==-1)
		return 1;

	pinMode(Trigger, OUTPUT);
	pinMode(Echo, INPUT);
	softToneCreate(Buzzer);
	float fDistance = 0;
	while(1) {
		if (digitalRead(Echo) == LOW){
			fDistance = getDistance();
		}else {
			pinMode(Echo, OUTPUT);
			digitalWrite(Echo, LOW);
			pinMode(Echo, INPUT);
		}
		printf("Distance : %.2fcm\n", fDistance);
		int cnt = 3;
		int scaleIndex = 8;
		if(fDistance > 0 && fDistance <= cnt*1){
			scaleIndex = 0;
		}else if(fDistance > cnt*1 && fDistance <= cnt*2){
			scaleIndex = 1;
		}else if(fDistance > cnt*2 && fDistance <= cnt*3){
			scaleIndex = 2;
		}else if(fDistance > cnt*3 && fDistance <= cnt*4){
			scaleIndex = 3;
		}else if(fDistance > cnt*4 && fDistance <= cnt*5){
			scaleIndex = 4;
		}else if(fDistance > cnt*5 && fDistance <= cnt*6){
			scaleIndex = 5;
		}else if(fDistance > cnt*6 && fDistance <= cnt*7){
			scaleIndex = 6;
		}else if(fDistance > cnt*7 && fDistance <= cnt*8){
			scaleIndex = 7;
		}else {
			scaleIndex = 8;
			softToneWrite(Buzzer, 0);
		}
		if (scaleIndex < 8){
			softToneWrite(Buzzer, scales[scaleIndex]);
			delay(200);
		}
		delay(200);
	}
	return 0;
}
