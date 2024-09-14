/**
* 백준 1차원 배열 10811 바구니 뒤집기
* N개의 바구니가 오름차순으로 정렬되어 있는데, (i ~ j)번 바구니를 M회 입력받아 순서를 역순으로 바꾼다. 
* 출력은 왼쪽부터 순서대로 출력한다.
*
* 제한사항
*****************************************
* 0 < N, M <= 100                       *
* 0 < i <= j <= N                       *
*****************************************
*
*
*
* 주의
* 
*
* 풀이시간 10분
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, M, i, j;
    scanf("%d%d", &N, &M);

    //배열 생성 및 초기화
    int* arr = (int*)malloc((N + 1) * sizeof(int));
    for (int t = 0; t < N+1; ++t)
    {
        arr[t] = t;
    }

    for (int t = 0; t < M; ++t)
    {
        scanf("%d%d", &i, &j);
        while (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    for (int t = 1; t < N+1; ++t)
    {
        printf("%d ", arr[t]);
    }
    free(arr);
    return 0;
}