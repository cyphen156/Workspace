#define _CRT_SECURE_NO_WARNINGS
// 백준 3009 네 번째 점
// 세 점을 주고 축에 평행한 직사각형을 그려야 한다 -> 길이를 줄테니 자표를 구해라
// x축 또는 y축에 평행한 직사각형 => 사다리꼴로 그려지지 않음
// 각 좌표가 순서대로 나오는 것이 아닌 랜덤 좌표
// 축에 평행하니 x좌표와 y좌표가 만나는 점이 반드시 존재
// 만나지 않는 한 좌표(x, y)를 특정해내야한다
/*
    제한사항
    int x, y
    1 <= x, y <= 1000
*/
#include <stdio.h>

int main() {
    int x[4] = { 0 }, y[4] = { 0 };
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    // x좌표비교
    if (x[0] == x[1])
        x[3] = x[2];
    else if (x[0] == x[2])
        x[3] = x[1];
    else
        x[3] = x[0];
    // y좌표 비교
    if (y[0] == y[1])
        y[3] = y[2];
    else if (y[0] == y[2])
        y[3] = y[1];
    else
        y[3] = y[0];

    printf("%d %d", x[3], y[3]);
    return 0;
}
