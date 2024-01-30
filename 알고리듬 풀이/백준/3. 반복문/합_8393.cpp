/**
* 백준 합 8393
* 1부터 입력받은 수 까지의 합을 출력한다.
* 
* 제한사항
*****************************************
* 0 < N <= 10,000						*
*****************************************
*
*
*
* 주의
* 
* 풀이시간 1분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N, sum = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) 
	{
		sum += i;
	}
	printf("%d", sum);
	return 0;
}