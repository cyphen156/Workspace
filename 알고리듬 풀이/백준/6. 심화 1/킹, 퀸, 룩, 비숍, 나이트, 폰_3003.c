/**
 * 백준 심화 1 킹, 퀸, 룩, 비숍, 나이트, 폰_3003
 * 
 * 하얀색 체스말이 일부가 많거나 모자라다. 갯수를 맞춰라
 * 
 * 제한사항
 *****************************************
 * King, Queen <= 1                      *
 * Rook, Bishop, Knight <= 2             *
 * Pawn <= 8                             *
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

int main(void)
{
    int black[6] = {1, 1, 2, 2, 2, 8};
    int white[6];

    for (int i = 0; i < 6; ++i)
    {
        scanf("%d", &white[i]);
    }

    for (int i = 0; i < 6; ++i)
    {
        printf("%d ", black[i] - white[i]);
    }
    return 0;
}