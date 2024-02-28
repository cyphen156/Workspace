/**
* 백준 반복문 2438 별 찍기-1
*
* 필수예제 별찍기
*
* 제한사항
*****************************************
* 0 < A <= 100							*
*****************************************
*
*
*
* 주의
*
*
* 풀이시간 1분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}