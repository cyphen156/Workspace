#include <softTone.h>
#include <softPwm.h>
#include <stdio.h>
#include <wiringPi.h>
#define Trigger	4
#define Echo	17
#define Buzzer	11
#define Led		9
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
	softPwmCreate(Led, 0, 100);
	pinMode(Led, OUTPUT);

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
		int index = 8;
		if(fDistance > 0 && fDistance <= cnt*1){
			index = 0;
		}else if(fDistance > cnt*1 && fDistance <= cnt*2){
			index = 1;
		}else if(fDistance > cnt*2 && fDistance <= cnt*3){
			index = 2;
		}else if(fDistance > cnt*3 && fDistance <= cnt*4){
			index = 3;
		}else if(fDistance > cnt*4 && fDistance <= cnt*5){
			index = 4;
		}else if(fDistance > cnt*5 && fDistance <= cnt*6){
			index = 5;
		}else if(fDistance > cnt*6 && fDistance <= cnt*7){
			index = 6;
		}else if(fDistance > cnt*7 && fDistance <= cnt*8){
			index = 7;
		}else {
			index = 8;
			softToneWrite(Buzzer, 0);
			softPwmWrite(Led, 0);
		}
		if(index < 8){
			softToneWrite(Buzzer, scales[index]);
			softPwmWrite(Led, 4+12*(index+1));
			delay(200);
		}
		delay(200);
	}
	return 0;
}
