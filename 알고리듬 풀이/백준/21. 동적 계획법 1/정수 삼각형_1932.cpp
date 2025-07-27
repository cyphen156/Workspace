/**
 * 백준 정수 삼각형_1932
 * 우선 다음 그림을 참고하자
 * 크기가 5인 정수 삼각형의 모습이다.
 * 
 *         7
 *       3   8
 *     8   1   0
 *   2   7   4   4
 * 4   5   2   6   5
 * 
 * 맨 위층의 Value부터 시작하여 아래에 있는 수 중 하나를 선택하여 내려갈 때 선택된 수의 합이 최대가 되도록 경로를 구하라
 * 선택할 수 있는것은 아래층의 대각선 노드 2개중 하나 뿐이다.
 * 
 * 제한사항
 *****************************************
 * 0 < TriangleSize <= 500               *
 * -1 < Value <= 9,999                   *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 10분
 */


#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE 501

static unsigned int triangle[MAX_SIZE][MAX_SIZE] = { 0 };
// static unsigned int memoizationArray[MAX_SIZE][MAX_SIZE] = { 0 }; // 궂이?

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            cin >> triangle[i][j];
        }
    }

    unsigned int result = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            // 좌하단 첫번째 원소 연산시 사용
            if (j == 0)
            {
                triangle[i][j] += triangle[i-1][j];
            }
            // 우하단 마지막 원소 연산시 사용
            else if (j == i)
            {
            triangle[i][j] += triangle[i-1][j-1];
            }
            else
            {
                triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        result = max(result, triangle[N-1][i]);
    }
    cout << result << '\n';
    return 0;
}

