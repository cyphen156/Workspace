/**
* 백준 문자열 2675 문자열 반복
* 문자열 S를 입력받고, 각 문자를 R번 반복해 새로운 문자열을 만들어 출력
* abcde, 3 -> aaabbbcccdddeee
* C -> 배열 저장
* C++ -> 바로 출력
* 
* 
* 제한사항
*****************************************
* 0 < Test T <= 1,000                   *
* 0 < S <= 20                           *
* 0 < R <= 8                            *
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
    int T;
    char str[21] = { 0 };

    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        int R, idx = 0;
        scanf("%d %s", &R, str);
        int length = strlen(str);
        char* S = (char*)malloc((R * length + 1) * sizeof(char));
        for (int j = 0; j < length; ++j)
        {
            for (int k = 0; k < R; ++k)
            {
                S[idx] = str[j];
                ++idx;
            }
        }
        S[idx] = '\0';
        printf("%s\n", S);
        free(S);
    }

    return 0;
}