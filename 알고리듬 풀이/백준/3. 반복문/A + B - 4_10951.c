/**
* 백준 반복문 10951 A + B - 4
*
* 간단하게 반복문을 사용한 덧셈 프로그램
* 
* 제한사항
*****************************************
* (0 < A, B < 10)                       *
*****************************************
*
*
*
* 주의
* 문제에 EOF조건이 명시되어 있지 않으니 주의
*
* 풀이시간 1분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int first, second;
    while (scanf("%d %d", &first, &second) !=EOF) {
        printf("%d\n", first + second);
    }
    return 0;
}
