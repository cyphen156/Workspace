#define _CRT_SECURE_NO_WARNINGS
/*
    백준 19532 수학은 비대면강의입니다.
    ax+by = c
    dx+ey = f
    => adx+bdy = dc
    => adx+aey = ac
    ==> (a-d)c = (ae-bd)y
    // 크래머 규칙(행렬 연산)
    // 가우스 소거법
*/
/*
    제한사항
    -999 <= a, b, c, d, e, f <= 999
    x, y 는 유일하다
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    int denominator = a * e - b * d;
    if (denominator == 0) {
        return 0;
    }

    int x = (c * e - b * f) / denominator;
    int y = (a * f - c * d) / denominator;
    printf("%d %d\n", x, y);

    return 0;
}