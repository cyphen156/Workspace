/**
* 백준 25314 코딩은 체육과목 입니다. 
* 입력받은 수를 기준으로 4바이트마다 
* long이라는 문자열을 하나씩 늘려가면서 출력하는 프로그램﻿
* 
* 
* 제한사항
*****************************************
* 4 <= N <= 1,000						*
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
	long long N;
	scanf("%lld", &N);
	N >>= 2; // 나누기 4 == 2bit shift
	for (long long i = 0; i < N; ++i)
	{
		printf("long ");
	}
	printf("int\n");
	return 0;
}