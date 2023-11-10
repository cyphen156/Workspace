/**
* 백준 N 찍기
*
* 단순 반복문 문제
*
*
* 제한사항
*****************************************
* 1 <= N <= 100,000						*
*****************************************
*
*
*
* 주의
*
* 풀이시간 1분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int N = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        printf("%d\n", i);
    }
    return 0;
}
