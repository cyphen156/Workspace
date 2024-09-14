/**
* 백준 1차원 배열 10813 공 바꾸기
* 한정된 숫자 내에서 빠진 숫자를 찾는 프로그램
*
* 제한사항
*****************************************
* 0 < N <= 30                           *
* nInput == 28                          *
*****************************************
*
*
*
* 주의
* 출력시 오름차순 정렬 출력
* 
*
* 풀이시간 5분
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N, cnt = 0; 
    int arr[31] = {0};

    for (int i = 0; i < 28; ++i)
    {   
        scanf("%d", &N);
        arr[N] = 1;
    }

    for (int i = 1; i < 31; ++i)
    {
        if (arr[i] == 0)
        {
            printf("%d\n", i);
            ++cnt;
        }
        if (cnt == 2)
        {
            break;
        }
    }
    return 0;
}