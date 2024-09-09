/**
* 백준 1차원 배열 10871
* 정수 N개로 이루어진 수열 A와 X를 주었을 때 X보다 작은 수를 모두 출력하라.
* 
* 제한사항
*****************************************
* 0 < N, X <= 10,000                   *
* 0 < result <= N                       *
*****************************************
*
*
*
* 주의
* 수를 입력받은 순서대로 공백을 주어 출력한다
* --> 정렬 안한다.
* ----> 브루트 포스식으로 전체를 순회해야한다.
*
* 풀이시간 10분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, X;
    scanf("%d %d", &N, &X);
    
    if (N > 10000)
    {
        return-1;
    }
    int* arr = (int*)malloc(N * sizeof(int));
    int* result = (int*)calloc(N, sizeof(int));
    int T = 0;
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &arr[i]);
        if (arr[i] < X)
        {
            result[T] = arr[i];
            ++T;
        }
    }
    for (int i = 0; result[i] != 0; ++i)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(arr);
    free(result);
	return 0;
}