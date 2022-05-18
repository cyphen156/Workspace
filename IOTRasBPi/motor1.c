#include <wiringPi.h>

#define MOTOR_MT_N_PIN	17
#define MOTOR_MT_P_PIN	4
#define LEFT_ROTATE	1
#define RIGHT_ROTATE	2
void MotorStop(){
	digitalWrite(MOTOR_MT_N_PIN, 0);
	digitalWrite(MOTOR_MT_P_PIN, 0);
}
void MotorControl(unsigned char rotate){
	if(rotate == LEFT_ROTATE){
		digitalWrite(MOTOR_MT_N_PIN, HIGH);
		digitalWrite(MOTOR_MT_P_PIN, LOW);
	}else if (rotate == RIGHT_ROTATE){
		digitalWrite(MOTOR_MT_N_PIN, LOW);
		digitalWrite(MOTOR_MT_P_PIN, HIGH);
	}
}
int main(void){
	if (wiringPiSetupGpio() == -1)
		return 1;
	pinMode(MOTOR_MT_N_PIN, OUTPUT);
	pinMode(MOTOR_MT_P_PIN, OUTPUT);

	while (1) {
		MotorControl(LEFT_ROTATE);
		delay(2000);
		MotorStop();
		MotorControl(RIGHT_ROTATE);
		delay(2000);
		MotorStop();
		delay(5000);
	}
	return 0;	
}