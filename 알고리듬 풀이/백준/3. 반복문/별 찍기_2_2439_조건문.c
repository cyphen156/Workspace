/**
* 백준 반복문 2438 별 찍기-1
*
* 너도알고 나도 알고 모두 아는 반복문 필수예제 별찍기 ver2
* 문자열 간격을 조정할 수 있어야한다.
* 조건문을 통한 문자열 제어
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
* 풀이시간 5분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (n-j >= i)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}