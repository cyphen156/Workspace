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
* Test = T      						*
* 1 <= W, H <= 99                       *
* 1 <= N <= W * H                       *
* ==> 1 <= N <= 99*99                   *
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
    int T = 0;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        // 행번호, 열번호, N번손님
        int W, H, N, floor = 1, room = 1;
        scanf("%d%d%d", &H, &W, &N);
        
        floor = N % H;
        room = N / H + 1;
        if (floor == 0) {
            floor = H;
            room--;
        }
        printf("%d%02d\n", floor, room);
    }
    return 0;
}
