/**
 * 백준 벌집_2292
 * 정육각형 모양의 중앙 방에서부터 시작하여 회전하면서 방에 번호를 매기고 최단거리를 구하는 프로그램방
 *  만드는 갯수의 수식은 from N=0 to N −1 ∑(6N) + 1개
 * 6N(N-1)/2 + 1
 * Room까지 가려면 걸리는 최단 거리 경로는 항상 N칸이다
 * 
 * 제한사항
 *****************************************
 * 0 < Rooms <= 1,000,000,000            *
 *****************************************
 *
 *
 *
 * 주의
 * 0 < Rooms <= 1,000,000,000
 * 
 * 풀이시간 10분
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
     
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int N, result = 1, i;
    scanf("%d", &N);
    for (i = 1; result < N; i++) {
        result += 6 * i;
    }
    printf("%d", i);
    return 0;
}