/**
* 백준 9086 문자열
* 입력받은 문자열의 첫 글자와 마지막 글자를 출력하는 프로그램
* C언어로는 문자열 저장안하고 문자 두개만을 저장할 것이다.
* 
* 
* 제한사항
*****************************************
* 0 < Test T <= 10                      *
* 0 < string <= 1,000                   *
* there is no 'spacing' in "str"        *
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

int main(void)
{
	int T;
    char start, end, input;
    scanf("%d", &T);
    getchar();

    for (int i = 0; i < T; ++i)
    {
        start = '\0';
        end = '\0';
        while(1)
        {
            scanf("%c", &input);
            if (input == '\n')
            {
                printf("%c%c\n", start, end);  
                break;
            }
            if (start == '\0')
            {
                start = input;
            }
            end = input;
        }
    }

	return 0;
}