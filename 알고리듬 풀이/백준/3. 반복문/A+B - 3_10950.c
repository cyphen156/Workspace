/**
* 백준 ﻿A+B - 3_10950
* 입력받은 두 정수의 합을 출력한다.
* 
* 제한사항
*****************************************
* Test == t;							*
* 0 < A, B < 10							*
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
	int t, A, B;
	scanf("%d", &t);

	for (int i = 0; i < t; ++i)
	{
		scanf("%d%d", &A, &B);
		printf("%d\n", A + B);
	}
	return 0;
}