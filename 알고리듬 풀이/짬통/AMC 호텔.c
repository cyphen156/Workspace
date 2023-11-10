/**
* 백준 ACM호텔 10250
* 
* 손님은 정문과 가장짧은 거리의 방을 선호, 도착하는대로 빈방 배정
* 
* W * H크기의 호텔, 각 층 H는 0번 인덱스로 지정 
* ==> 정문으로 사용 가능 but 같은 거리일때 낮은 층 선호
*
* ==> 행번호 우선 배정, 열번호 거리는 ++연산
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
* 풀이시간 60분
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
