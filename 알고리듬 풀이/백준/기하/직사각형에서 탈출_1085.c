#define _CRT_SECURE_NO_WARNINGS
// 백준 1085 직사각형에서 탈출
// 한수의 좌표에서 x축 또는 y축으로의 거리가 짧은지,  아니면 w, h로의 걸이가 짧은지 구하기
// 단순히 좌표 밖으로 나가기만 하면 되기 때문에 대각선은 구할필요가 없음
// w, h의 절반길이 기준으로 0 또는 w/ h까지의 거리가 정해짐
/*
    제한사항
    1 ≤ w, h ≤ 1,000
    1 ≤ x ≤ w-1
    1 ≤ y ≤ h-1
    x, y, w, h는 정수
*/
#include <stdio.h>

int main() {
    //한수의 좌표 (x, y) 직사각형의 길이 (w, h)
    int x, y, w, h, min = 1001;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    //거리 차이 계산
    if (x > w - x)
        x = w - x;
    if (y > h - y)
        y = h - y;

    min = x;
    if (x > y)
        min = y;
    printf("%d", min);
    return 0;
}
