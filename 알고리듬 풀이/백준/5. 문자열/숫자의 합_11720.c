/**
* 백준 11720 숫자의 합
* N개의 숫자가 공백없이 입력될 때 이 숫자를 모두 합해서 출력하는 프로그램
* 문자열로 입력받아 1개씩 쪼개 데이터를 저장하기
* 
* 
* 제한사항
*****************************************
* 0 < N <= 100                          *
*****************************************
*
*
*
* 주의
* 없다.
* 
* 풀이시간 5분
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N, sum = 0;

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; ++i)
    {
        char ch;
        scanf("%c", &ch);
        sum += ((int)ch-48);
    }

    printf("%d\n", sum);
	return 0;
}