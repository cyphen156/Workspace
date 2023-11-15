/**
* 백준 검증수 2475
*
* 6자리 고유번호
* 6번은 검증수, 5개는 시리얼넘버
*
* 검증수  = 시리얼넘버의 각 자리수 **의 합 % 10
*
*
* 제한사항
*****************************************
* 0 <= N <= 9                           *
*****************************************
*
*
*
* 주의
*
* 풀이시간 10분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int result = 0;
    for (int i = 0; i < 5; ++i) {
        int n = 0;
        scanf("%d", &n);

        result += n * n;
    }
    printf("%d", result % 10);
    return 0;
}
