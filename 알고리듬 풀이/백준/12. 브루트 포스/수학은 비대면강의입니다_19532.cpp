/**
 * 백준 수학은 비대면강의입니다_19532
 * 제목과 전혀 상관없는 문제
 * 이차방정식의 해를 구하라
 * 이차방정식의 근의 공식 
 * => ad - bc
 * ==> ae - bd
 * 
 * 제한사항
 *****************************************
 * ax + by = c                           *
 * dx + ey = f                           *
 * -1,000 < a, b, c, d, e, f < 1,000     *
 *****************************************
 *
 * 
 * 
 * 주의
 * x와 y를 공백으로 구분해 출력한다.
 * 
 * 풀이시간 5분
 */


#include <iostream>

using namespace std;

int main(void)
{
    int a, b, c, d, e, f;
    int x = 0, y = 0;
    cin >> a >> b >> c >> d >> e >> f;

    int denominator = a * e - b * d;
    if (denominator == 0) {
        return 0;
    }

    x = (c * e - b * f) / denominator;
    y = (a * f - c * d) / denominator;
    cout << x << " " << y << endl;
    return 0;
}