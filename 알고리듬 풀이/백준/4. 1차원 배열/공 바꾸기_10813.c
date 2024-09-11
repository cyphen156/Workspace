/**
* 백준 1차원 배열 10813 공 바꾸기
* 이전 문제에서 이어지는 연계문제, 초기에 공이 모두 N번 바구니에 N번 공이 들어가있다고 가정한다. 
* M번 교환을 시도하는데 두 바구니를 선택하여 서로 공을 교환한다.
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
* 간단한 변수 교체 가능 여부를 물어보는 문제이다. 임시변수를 사용하여 두 바구니에 있는 공들을 바꾼다.
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

    int* arr = (int*)malloc(N * sizeof(int));

    // 바구니 초기화
    for (int k = 0; k < N; ++k)
    {
        arr[k] = k+1;
    }

    // 공 바꾸기
    for (int k = 0; k < M; ++k)
    {
        scanf("%d%d", &i, &j);
        int tmp = arr[i-1];
        arr[i-1] = arr[j-1];
        arr[j-1] = tmp;
    }

    for (int k = 0; k < N; ++k)
    {
        printf("%d ", arr[k]);
    }
    return 0;
}