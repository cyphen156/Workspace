/**
* 백준 1차원 배열 2562 최댓값
* 9개의 서로 다른 자연수가 주어질 때 최댓값을 찾고 몇번째 수인지 구하는 프로그램을 작성하시오.
* 배열을 사용한 위치 저장, 순회하면서 확인
*
* 제한사항
*****************************************
* 0 < INPUT < 100                       *
*****************************************
*
*
*
* 주의
* 첫째 줄에 최댓값을 출력하고, 둘째 줄에 몇번째 수인지 출력한다.
*
* 풀이시간 5분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int INPUT, MAX = 0, cnt = 0;
    int arr[9] = { 0 };

    for (int i = 0; i < 9; ++i)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 10; ++i)
    {
        if (arr[i] > MAX)
        {
            MAX = arr[i];
            cnt = i + 1;
        }
    }
    printf("%d\n%d", MAX, cnt);
	return 0;
}