/**
 * 백준 직사각형에서 탈출_1085
 * 직사각형의 경계까지 가는 최소값을 구하는 프로그램
 * (x, y)라는 기준점에서 w, h까지의 거리를 연산해 비교하여 최소한의 거리로 가야한다.
 * 대각선 거리는 고려하지 않는다.
 * 
 * 제한사항
 *****************************************
 * 0 < x, y < w, h <= 100                *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 0분
 */


#include <iostream>

using namespace std;

int main(void)
{
    int x, y, w, h;
    
    cin >> x >> y >> w >> h;

    int left = x;
    int right = w - x;
    int bottom = y;
    int top = h - y;

    int min;

    if (x > w - x)
        x = w - x;
    if (y > h - y)
        y = h - y;

    min = x;
    if (x > y)
        min = y;
    cout << min << endl;
    return 0;
}