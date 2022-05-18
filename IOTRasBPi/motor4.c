#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#define MOTOR_MT_N_PIN 17
#define MOTOR_MT_P_PIN 4
#define Trigger 11
#define Echo 9
const int d_pwm[]={100, 80, 55, 35, 15, 5};
float getDistance(void){ 
	float fDistance;
	int nStartTime, nEndTime;
	digitalWrite(Trigger, LOW);
	delayMicroseconds(2);
	digitalWrite(Trigger, HIGH);
	delayMicroseconds(10);
	digitalWrite(Trigger, LOW);
	while(digitalRead(Echo)==LOW);
	nStartTime=micros();
	while(digitalRead(Echo)==HIGH);
	nEndTime=micros();
	fDistance=(nEndTime-nStartTime)/58.0;
	return fDistance;
}
int main(void) { 
	if(wiringPiSetupGpio()==-1)
		return 1;
	pinMode(MOTOR_MT_N_PIN, OUTPUT);
	pinMode(MOTOR_MT_P_PIN, OUTPUT);
	softPwmCreate(MOTOR_MT_N_PIN, 0, 100);
	softPwmCreate(MOTOR_MT_P_PIN, 0, 100);
	pinMode(Trigger, OUTPUT);
	pinMode(Echo, INPUT);
	float fDistance=0;
	int pwmIndex;
	while(1) {
		if(digitalRead(Echo)==LOW) {
			fDistance=getDistance();
		} else{
			pinMode(Echo, OUTPUT);
			digitalWrite(Echo, LOW);
			pinMode(Echo, INPUT);
		}
		printf("Distance: %.2fcm\n", fDistanceint cnt=3;
		if(fDistance>0 && fDistance<=cnt*1){
			pwmIndex=0; 
		}else if(fDistance>cnt*1 && fDistance<=cnt*2){
			pwmIndex=1; 
		}else if(fDistance>cnt*2 && fDistance<=cnt*3){
			pwmIndex=2; 
		}else if(fDistance>cnt*3 && fDistance<=cnt*4){
			pwmIndex=3; 
		}else if(fDistance>cnt*4 && fDistance<=cnt*5){
			pwmIndex=4; 
		}else if(fDistance>cnt*5 && fDistance<=cnt*6){
			pwmIndex=5; 
		}else { 
			pwmIndex=6; 
			digitalWrite(MOTOR_MT_P_PIN, LOW);
			softPwmWrite(MOTOR_MT_N_PIN, 0); 
		}
		if(pwmIndex<6) {
			digitalWrite(MOTOR_MT_P_PIN, LOW);
			softPwmWrite(MOTOR_MT_N_PIN, d_pwm[pwmIndex]);
			delay(200);
		}
		delay(200);
	}
	return 0;
}