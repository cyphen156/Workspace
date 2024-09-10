/**
* 백준 1차원 배열 10818 최소, 최대
* 입력된 정수들의 최소, 최대값을 구하는 프로그램
* 두가지 방법이 존재한다.
* 모든 정수를 입력받은 이후 최소, 최대값을 연산할 것인지?->C풀이
* 입력받는 즉시 최소, 최대값을 비교하여 순회 횟수를 줄일 것인지?-> C++풀이
* 
* 제한사항
*****************************************
* 0 < N <= 1,000,000                    *
* -1,000,000 <= INPUT <= 1,000,000      *
*****************************************
*
*
*
* 주의
* 첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.
*
* 풀이시간 5분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    // 초기 min값은 Intiger의 최대값, 초기 min값은 최소값
    // unsigned 자료형이 아니므로 절반을 나누어 음수 처리 필요
    // <limits.h>에서 INT_MIN, INT_MAX를 통해 처리 가능
    // ex 0x7FFFFFFF = 2147483647, 0x80000000 = -2147483648
    // or 
    // MIN = 1,000,000, MAX = 1,000,000 으로 처리 가능
	int N, MIN = 0x7FFFFFFF, MAX = 0x80000000;

    scanf("%d", &N);
    int* arr = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < N; ++i)
    {
        if (arr[i] <= MIN)
        {
            MIN = arr[i];
        }
        if (arr[i] >= MAX)
        {
            MAX = arr[i];
        }
    }
    printf("%d %d", MIN, MAX);
	return 0;
}