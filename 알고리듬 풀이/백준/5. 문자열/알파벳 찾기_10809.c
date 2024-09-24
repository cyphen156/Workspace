/**
* 백준 문자열 10809 알파벳 찾기
* 알파벳 표에서 입력받은 문자열에 해당 알파벳이 등장하는 첫 위치를 표시하는 프로그램
* 
* 
* 제한사항
*****************************************
* 0 < S <= 100                          *
* S is Lowercase                        *
* if ch is not in S return -1           *
*****************************************
*
*
*
* 주의
* 없다.
* 
* 풀이시간 10분
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void)
{
    int alpha[26];
    int len = sizeof(alpha)/sizeof(alpha[0]);

    char str[101];
    // alpha 초기화
    for (int i = 0; i < len; ++i)
    {
        alpha[i] = -1;
    }

    scanf("%s", str);
    
    for (int i = 0; i < strlen(str); ++i)
    {
        int idx = str[i] - 'a';
        if (alpha[idx] == -1)
        {
            alpha[idx] = i;
        }
    }

    for (int i = 0; i < len; ++i)
    {
        printf("%d ", alpha[i]);
    }
    printf("\n");
	return 0;
}