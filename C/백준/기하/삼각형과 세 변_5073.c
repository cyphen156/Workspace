#define _CRT_SECURE_NO_WARNINGS
/*
    백준 5073 삼각형과 세 변
    Equilateral :  세 변의 길이가 모두 같은 경우
    Isosceles : 두 변의 길이만 같은 경우 =ㅉ 이등변삼각형
    Scalene : 세 변의 길이가 모두 다른 경우, 가장 긴 변 < 나머지 두 변의 합
    Invalid : 삼각형이 아닌 경우
*/ 
/*
    제한사항
    1 <= n <= 1000
*/
#include <stdio.h>

int main() {
    int a, b, c;
    while (1) {
        int max, sum = 0;
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0)
            break;
        max = a > b ? a : b;
        max = max > c ? max : c;
        // 가장 긴 변과, 나머지 두 변의 길이 합 구하기
        if (max == a)
            sum = b + c;
        else if (max == b)
            sum = a + c;
        else sum = a + b;

        if (max >= sum)
            printf("Invalid\n");
        else if (a == b && b == c)
            printf("Equilateral\n");
        else if (a == b || b == c || a == c)
            printf("Isosceles\n");
        else
            printf("Scalene\n");
    } 
    return 0;
}
