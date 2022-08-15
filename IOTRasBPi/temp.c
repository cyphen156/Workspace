#include "sensor.h" // 센서 제어 관련 헤더 파일 포함
volatile float temp; // 온,습도 값 저장 변수 선언
volatile float humi;
int main(void)
{ 
    if(wiringPiSetupGpio() == -1)
        return 1;
    SHT11_Init(); // 온,습도 센서 초기 설정
    while(1)
    {
        Transmission_start(); // 전송 시작
        temp = get_SHT11_data(TEMP); // 온도 센싱
        delay(100);
        Transmission_start(); // 전송 시작
        humi = get_SHT11_data(HUMI); // 습도 센싱
        delay(100);
        printf("Temp = %2.2f[C], Humi = %2.2f[%]\n", temp, humi);
    }
    return 0;
}
