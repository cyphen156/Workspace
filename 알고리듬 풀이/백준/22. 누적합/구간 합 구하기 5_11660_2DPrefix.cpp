/**
 * 백준 구간 합 구하기 5_11660_2DPrefix
 * N X N의 행렬이 존재한다. 
 * (X1, Y1) 부터 (X2, Y2)까지의 합을 구하는 프로그램을 작성하라.
 * 예를 들어 (2, 2) ~ (3, 4)의 누적 합은 빨간 범위이고, 
 * (4, 4) ~ (4, 4)까지의 누적 합은 파란 범위이다.
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 1025                         *
 * 1 <= M < 100,001                      *
 * 1 <= value < 1001                     *
 * X1 <= X2                              *
 * Y1 <= Y2                              *
 *****************************************
 *
 *
 *
 * 주의
 * 이차원 누산 합 구현
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 5분
 */


#include <iostream>

#define MAX_SIZE 1025

using namespace std;

static int values[MAX_SIZE][MAX_SIZE] = { 0 };  // 행 열
static int prefixSum[MAX_SIZE][MAX_SIZE] = { 0 };
static int N, M;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> values[i][j];
            prefixSum[i][j] = prefixSum[i - 1][j]        // 행, 열 기준 2차원 누산 합
                            + prefixSum[i][j - 1]
                            - prefixSum[i - 1][j - 1]
                            + values[i][j]; 
        }
    }

    for (int i = 0; i < M; ++i)
    {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;
        int maxSum = prefixSum[x2][y2]
                    - prefixSum[x1 - 1][y2]
                    - prefixSum[x2][y1 - 1]
                    + prefixSum[x1 - 1][y1 - 1];

        cout << maxSum << '\n';
    }

    return 0;
}