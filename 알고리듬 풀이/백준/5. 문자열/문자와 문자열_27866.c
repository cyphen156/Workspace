/**
* 백준 27866 문자와 문자열
* 단어 S와 정수 i가 주어졌을 때 i번 째 글자를 출력하는 프로그램
* 
* 제한사항
*****************************************
* 0 < S <= 1,000						*
* 0 < i <= S							*
*****************************************
*
*
*
* 주의
* i는 인덱스이므로 문자열 배열의 시작은 항상 0임을 기억해야한다.
* 
* 
* 풀이시간 1분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	char string[1001];
	int i;

	scanf("%s %d", string, &i);

	printf("%c\n", string[i-1]);
	return 0;
}