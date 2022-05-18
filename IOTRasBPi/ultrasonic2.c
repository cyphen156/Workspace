#include <softTone.h>
#include <stdio.h>
#include <wiringPi.h>
#define Trigger	4
#define Echo	17
#define Buzzer	11

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
	if(fDistance <= 5.00){
		softToneWrite(Buzzer, 500);
		delay(200);
		softToneWrite(Buzzer, 0);
		delay(5);
	}
	delay(1000);
	}
	return 0;
}
