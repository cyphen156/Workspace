#include "sensor.h" // 센서 제어 관련 헤더 파일 포함
#define P_PIN 11
#define N_PIN 9
volatile float temp; // 온,습도 값 저장 변수 선언
volatile float humi;


int main(void)
{ 
    if(wiringPiSetupGpio() == -1)
        return 1;
    SHT11_Init();
    pinMode(P_PIN, OUTPUT);
    pinMode(N_PIN, OUTPUT);
    while(1){
        Transmission_start();
        temp = get_SHT11_data(TEMP);
        delay(100);
        Transmission_start();
        humi = get_SHT11_data(HUMI);
        delay(100);
        printf("Temp = %2.2f[C], Humi = %2.2f[%]\n", temp, humi);
        if(temp >= 25){//센서가 측정한 온도가 25도 이상일 경우 팬이 계속 돌아감
            digitalWrite(P_PIN, HIGH);
            digitalWrite(N_PIN, LOW);
        }else {//25도 미만일 경우 팬을 멈춤
            digitalWrite(P_PIN, LOW);
            digitalWrite(N_PIN, LOW);
        }
        
    }
    return 0;
}
