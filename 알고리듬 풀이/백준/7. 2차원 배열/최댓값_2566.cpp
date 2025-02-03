/**
 * 백준 최댓값_2566
 * 9 * 9 행렬안에 있는 값 중 최댓값을 찾고 그 위치를 출력하라.
 * 
 * 제한사항
 *****************************************
 * 0 <= Value < 100                      *
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
    int array[9][9] = {0};
    int maxVal = -1, maxRow = -1, maxCol = -1;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cin >> array[i][j];
            if (maxVal < array[i][j])
            {
                maxVal = array[i][j];
                maxRow = i+1;
                maxCol = j+1;
            }
        }
    }

    cout << maxVal << '\n' << maxRow << " " << maxCol;
    return 0;
}