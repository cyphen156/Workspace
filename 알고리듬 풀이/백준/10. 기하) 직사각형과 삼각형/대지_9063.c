#define _CRT_SECURE_NO_WARNINGS
// 백준 9063 대지
// 잃어버린 땅문서, 표식찾기
// 임씨의 이름이 새겨진 옥구슬이 나오는 모든 지점을 포함하는 
// 가장 작은 남북, 동서 방향으로 평행한 변을 갖는 직사각형
// 핵심 포인트는 가장 최소가 되는 좌표와 최대가 되는 좌표를 구한 뒤
// 직사각형의 넓이를 구한다.
// 중간좌표지점들은 무시한다.
/*
    제한사항
    점의 개수 
    1<= n <= 100,000
    각 점의 좌표(int)
    -10,000 <= x, y <= 10,000
*/
#include <stdio.h>

int main() {
    int n, point[2][100001];
    int minX = 10001, minY = 10001, maxX = -10001, maxY = -10001;
    long long w, h, square;
    // 좌표 초기화 != 0 , 제한 범위 밖으로 지정, 예외처리
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 100001; j++) {
            point[i][j] = 10001;
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &point[0][i], &point[1][i]);
        if (point[0][i] < minX) minX = point[0][i];
        if (point[1][i] < minY) minY = point[1][i];
        if (point[0][i] > maxX) maxX = point[0][i];
        if (point[1][i] > maxY) maxY = point[1][i];
    }
    w = maxX - minX;
    h = maxY - minY;

    square = w * h;
    printf("%lld", square);
    return 0;
}
