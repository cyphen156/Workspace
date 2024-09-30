/**
* 백준 2908 상수
* 두 수를 입력받고 입력받은 자릿수를 역순으로 바꾼 후 비교하여 큰 수를 출력하면 된다.
* 이 문제의 핵심은 입력 데이터의 강제 형변환 또는 자릿수 파싱, 그리고 비교 연산이다.
* 
* 
* 제한사항
*****************************************
* 0 < Input < 1,000                     *
*****************************************
*
*
*
* 주의
* 없다.
* 
* 풀이시간 5분
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    char num1[4], num2[4];
    char temp;

    scanf("%s %s", num1, num2);

    temp = num1[0];
    num1[0] = num1[2];
    num1[2] = temp;

    temp = num2[0];
    num2[0] = num2[2];
    num2[2] = temp;

    for (int i = 0; i < 3; i++) {
        if (num1[i] > num2[i]) {
            printf("%s", num1);
            break;
        }
        else if (num1[i] < num2[i]) {
            printf("%s", num2);
            break;
        }
    }

    return 0;
}