#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
//bool LEDCONTROL = false; 부울린 자료형을 사용하기 위한 헤더
#include <stdbool.h> 

//따로 만든 라즈베리파이 모듈 제어함수가 모여있는 헤더파일
#include "modules.h" 

//포트번호
#define PORT    9005  

int main(void){

    //프로그램 실행시 사용되는 변수들
    int n; //버퍼의 길이
    int len; //버퍼의 길이
    char rcvBuffer[BUFSIZ]; 
    int value; //안드로이드 클라이언트 프로그램으로부터 받은 정수헝 변수를 저장합니다.
    bool LEDCONTROL = false; //LED의 활성 상태를 체크하는 부울형 변수

    //GPIO세팅이 비정상적이면 프로그램을 종료합니다
    if (wiringPiSetupGpio()==-1)
        return -1;
    
    //LED핀을 세팅합니다
    pinMode(LED_PIN, OUTPUT);
    softPwmCreate(LED_PIN, 0, 100);

    //모터핀을 세팅합니다
    pinMode(MOTOR_MT_N_PIN, OUTPUT);
    pinMode(MOTOR_MT_P_PIN, OUTPUT);
    softPwmCreate(MOTOR_MT_N_PIN, 0, 100);
    softPwmCreate(MOTOR_MT_P_PIN, 0, 100);

    //파일입출력을 담당할 소켓 통신을 세팅합니다.
    int s_socket, c_socket;
    struct sockaddr_in s_addr, c_addr;

    s_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    memset(&s_addr, 0, sizeof(s_addr));
    s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(PORT);

    if(bind(s_socket, (struct sockaddr*)&s_addr, sizeof(s_addr))==-1){
        printf("can not bind!!\n");
        return -1;
    }

    if(listen(s_socket, 5)== -1){
        printf("listen fail!!\n");
        return -1;
    }

    //모듈 연결과 소켓이 정상적으로 생성되면 "project server started...\n"를 출력합니다.
    printf("project server started...\n");
    while (1)
    {
        len = sizeof(c_addr);
        c_socket = accept(s_socket, (struct sockaddr*)&c_addr, &len);
        printf("connected ip: %s\n", inet_ntoa(c_addr.sin_addr));

        while((n = read( c_socket , rcvBuffer , sizeof(rcvBuffer))) >0)
        {
            rcvBuffer[n] = '\n';
            /*
            원래는 클라이언트에서 출력버퍼에 모듈제어 + value값을 서버로 보낸 후
            서버에서 버퍼를 통해 받은 데이터를 파싱(Parsing)해서 따로 컨트롤 하려 했는데
            value값을 정수형 데이터로 변환하면 모두 0으로 찍히는 문제가 발생하여 파싱부분을 제외했습니다.
            char *str = strtok(rcvBuffer, "+");
            printf("2%s\t", str);
            int speed;
            while(str != NULL) {
                printf("3%s\t", str);
                str = strtok(NULL, "+");
            }
            speed = (int)str;
            printf("4str+%s\t", str);
            printf("5speed+%d\t", speed);
            delay(899);
            */
            
            //LED동작 컨트롤
            //버퍼를 통해 들어온 데이터가
            if(strncmp(rcvBuffer, "LEDOn", 5) == 0){ //LEDOn이면
                LedOn();                             //modules.h의 LEDOn함수를 사용해 LED를 켜고
                if (LEDCONTROL == false)
                    LEDCONTROL = true;               //LEDCONTROL을 True로 바꿔줍니다.
            }else if (strncmp(rcvBuffer, "LEDOff", 6)==0){ //LEDOff이면
                printf("%s", rcvBuffer);
                LedOff();                           //modules.h의 LEDOn함수를 사용해 LED를 켜고
                if (LEDCONTROL == true) 
                    LEDCONTROL = false;             //LEDCONTROL을 false로 바꿔줍니다.
            }

            //모터 동작 컨트롤
            //버퍼를 통해 들어온 데이터가
            if(strncmp(rcvBuffer, "MTOn", 4) == 0){ //MTOn이면  
                MotorControl(0);                    //modules.h의 MotorControl()함수를 사용해 모터를 켜고 속도는 0으로 줍니다.
            }else if (strncmp(rcvBuffer, "MTOff", 5)==0){ //MTOff이면
                printf("%s", rcvBuffer);
                MotorStop();                        //modules.h의 MotorStop함수를 사용해 모터를 끕니다.
            }else{                                  //그 외의 경우
                value = atoi(rcvBuffer);            //버퍼를 통해 받은 문자열을 Int형 정수로 변환하여 value에 대입합니다.
                MotorControl(value);                //modules.h의 MotorControl()함수를 사용해 모터를 켜고 속도는 value값으로 줍니다.
                if (LEDCONTROL == 1)                //만약 LED가 켜져있으면
                    LedControl(value);              //LED의 밝기도 제어합니다.
            }
        }
        printf("client Bye!\n");
        close(c_socket);                            //클라이언트와의 연결 종료
    }
    printf("server Close\n");
    close(s_socket);                                //소켓 통신 종료
    return 0;                                       
}