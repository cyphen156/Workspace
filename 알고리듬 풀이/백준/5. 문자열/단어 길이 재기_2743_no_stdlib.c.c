/**
* 백준 2743 단어 길이 재기
* 알파벳으로 이루어진 단어를 입력 받고 길이를 재는 프로그램
* 이번 것은 간단하게 stdlib과 미사용법 모두 써보겟다.
* 
* 
* 제한사항
*****************************************
* 0 < S <= 1,000						*
*****************************************
*
*
*
* 주의
* 문자열 입력시 항상 문자열의 마지막에는 문자열의 마지막을 알리는 '\0' 즉, 널문자이 포함된다. 
* 
* 풀이시간 1분
*/

// stdlib 미사용
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	char str[1001];
	int size = 0;
	
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; ++i)
	{
		++size;
	}
	printf("%d\n", size);
	return 0;
}