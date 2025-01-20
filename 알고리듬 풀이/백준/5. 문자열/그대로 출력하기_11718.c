/**
* 백준 그대로 출력하기_11718
* 입력받은 대로 문자열을 출력하면 된다.
*
* 제한사항
*****************************************
* input case == alpha, blank, intiger   *
* 0 <= input trial <= 100               *
* 0 <= input case len <= 100            *
* input case do not start and end blank *
*****************************************
*
*
*
* 주의
* scanf를 쓰면 공백문자 발생시 다른 문자열로 처리되므로 다른 방법을 써야한다.
*
* 풀이시간 10분
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    char ch;
    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }
    return 0;
}