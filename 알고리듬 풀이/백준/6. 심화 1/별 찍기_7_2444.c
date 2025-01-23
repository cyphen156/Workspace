/**
 * 백준 별 찍기 - 7_2444
 * 
 *     *
 *    ***
 *   *****
 *  *******
 * *********
 *  *******
 *   *****
 *    ***
 *     *
 * 
 * 그려라
 * 
 * 제한사항
 *****************************************
 * 없다.                                 *
 *****************************************
 *
 *
 *
 * 주의
 * 
 * 
 * 풀이시간 10분
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int input = 0;
    
    scanf("%d", &input);
    for (int i = 0; i < input; ++i)
    {
        for (int j = 0; j < input-i-1; ++j)
        {
            printf(" ");
            
        }
        for (int j = 0; j < (2*i)+1; ++j)
        {
            printf("*");        
        }
        printf("\n");
    }
    for (int i = 0; i < input-1; ++i)
    {
        for (int j = 0; j < i+1; ++j)
        {
            printf(" ");
            
        }
        for (int j = 0; j < 2 * (input-2-i) + 1; ++j)
        {
            printf("*");        
        }
        printf("\n");
    }
    return 0;
}