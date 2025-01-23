/**
 * 백준 팰린드롬인지 확인하기_10988
 * 팰린드롬이란 앞에서 부터 읽던지 뒤에서 부터 읽던지 똑같은 단어를 의미한다
 * 슈퍼주니어 노래중에 로꾸꺼를 한번 들어보면 확실하게 감이 온다.
 * 수박이박수, LeveL과 같은 단어가 팰린드롬이다.
 * 
 * 제한사항
 *****************************************
 * 1 <= string length <= 100             *
 * string is lowerCase                   *
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
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[101];
    int len = 0;
    scanf("%s", str);
    len = strlen(str);
    for (int i = 0; i < len/2; ++i)
    {
        if (str[i] != str[len-i-1])
        {
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
    return 0;
}