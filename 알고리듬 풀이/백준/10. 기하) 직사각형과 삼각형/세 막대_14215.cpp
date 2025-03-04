/**
 * 백준 세 막대_14215
 * 주어진 세 변의 길이를 줄일 수 있을 때 삼각형의 둘레 길이를 최대로 갖는 프로그램을 작성해라.
 * 삼각형의 성립 조건을 고려하여 둘레길이를 구하라.
 * 
 * 제한사항
 *****************************************
 * 0 < a, b, c <= 100                    *
 * 각 변은 모두 정수이다.                 *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 20분
 */


#include <iostream>

using namespace std;

int main(void)
{
    int lines[3] = { 0 };
    for (int i = 0; i < 3; ++i)
    {
        cin >> lines[i];
    }

    // 내림차순정렬
    for (int i = 0; i < 3; ++i)
    {
        for (int j = i; j < 3; ++j)
        {
            int temp = lines[i];
            if (lines[i] < lines[j])
            {
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }

    if (lines[0] >= lines[1] + lines[2]) {
        lines[0] = lines[1] + lines[2] - 1;
    }

    // 최댓값 출력
    cout << (lines[0] + lines[1] + lines[2]) << endl;

    return 0;
    return 0;
}