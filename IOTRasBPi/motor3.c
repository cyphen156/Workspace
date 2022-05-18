#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#define MOTOR_MT_N_PIN 17
#define MOTOR_MT_P_PIN 4
#define KEYPAD_PB1 6
#define KEYPAD_PB2 12
#define KEYPAD_PB3 13
#define KEYPAD_PB4 16
#define LEFT_ROTATE 1
#define RIGHT_ROTATE 2
#define STOP -1
#define MAX_SPEED 100
#define MIN_SPEED 0
int current_speed;
int current_direction;
const int keypad[4] = {
	KEYPAD_PB1, KEYPAD_PB2, KEYPAD_PB3, KEYPAD_PB4
};
void startISR(void) {
	current_speed = MAX_SPEED / 2;
	current_direction = LEFT_ROTATE; 
}
void speedUpISR(void) {
	if(current_speed <= MAX_SPEED){
		current_speed += 20;
	}else{
		current_speed = MAX_SPEED;
	}
} 
void speedDownISR(void){
	if(current_speed >= MIN_SPEED){
		current_speed -= 20;
	}else{
		current_speed = MIN_SPEED;
	}
}
void stopISR(void) {
	softPwmWrite(MOTOR_MT_N_PIN, MIN_SPEED);
	softPwmWrite(MOTOR_MT_P_PIN, MIN_SPEED);
	current_speed = MIN_SPEED;
	current_direction = STOP;
}
void (* functionISR[4]) (void) = {
	startISR, speedUpISR, speedDownISR, stopISR
};
void MotorStop(){
	softPwmWrite(MOTOR_MT_N_PIN, MIN_SPEED);
	softPwmWrite(MOTOR_MT_P_PIN, MIN_SPEED);
}
void MotorControl(unsigned char rotate, int speed){
	if(rotate == LEFT_ROTATE){
		digitalWrite(MOTOR_MT_P_PIN, LOW);
		softPwmWrite(MOTOR_MT_N_PIN, speed);
	}else if(rotate == RIGHT_ROTATE){
		digitalWrite(MOTOR_MT_N_PIN, LOW);
		softPwmWrite(MOTOR_MT_P_PIN, speed);
	}
}
int main(void){
	if(wiringPiSetupGpio() == -1) 
		return 1;
	pinMode(MOTOR_MT_N_PIN, OUTPUT);
	pinMode(MOTOR_MT_P_PIN, OUTPUT);
	int i;
	for(i = 0; i < 4; i++){
		pinMode(keypad[i], INPUT);
	}
	softPwmCreate(MOTOR_MT_N_PIN, MIN_SPEED, MAX_SPEED);
	softPwmCreate(MOTOR_MT_P_PIN, MIN_SPEED, MAX_SPEED);
	for(i = 0; i < 4; i++){
		if(wiringPiISR(keypad[i], INT_EDGE_FALLING, functionISR[i]) < 0){
		return 1;
		}
	}
	printf("1: start(Left) 2: Speed Up 3: Speed Down 4: Stop\n");
	MotorStop();
	delay(500);
	while(1){
		MotorControl(current_direction, current_speed);
		delay(3000); 
	}
	return 0;
}