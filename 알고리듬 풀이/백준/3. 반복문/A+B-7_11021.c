/**
* 백준 반복문 11021 A+B - 7
* 
* 테스트 케이스 번호를 동시에 출력하는 덧셈프로그램
* 
* 제한사항
*****************************************
* 0 < A, B < 10							*
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
	int T;
	scanf("%d", &T);
	int A, B;
	for (int i = 0; i < T; ++i)
	{
		scanf("%d%d", &A, &B);
		printf("Case #%d: %d\n", i+1, A + B);
		getchar();	// 버퍼 \n비우기
	}
	return 0;
}