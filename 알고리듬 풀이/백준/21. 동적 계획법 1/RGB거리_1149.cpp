/**
 * 백준 RGB거리_1149
 * N개의 집이 있는데 집은 빨강, 초록, 파랑 셋 중 하나의 색으로 칠해야 한다.
 * 각각의 색칠 비용이 주어졌을 때 모든 집을 칠하는 최소 비용을 구하라.
 * 
 * 제한사항
 ********************************************************************
 *                                                                  *
 * 1 < N <= 1,000                                                   *
 * 0 < eachPrice <= 1000                                            *
 *                                                                  *
 *******************아래 3개 규칙은 다 똑같은 소리다*******************
 ********************이따위 말장난좀 안했으면 좋겟다*******************
 *                                                                  *
 * 1번 집의 색은 2번 집의 색과 같지 않아야 한다.                       *
 * N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.                     *
 * i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다. *
 *                                                                  *
 ********************************************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 10분
 */


#include <iostream>
#include <algorithm>

#define MAX_SIZE 1001

using namespace std;

static int N;
static int priceArray[MAX_SIZE][3] = { 0 };
static int memoizationArray[MAX_SIZE][3] = { 0 };
static int minPrice = 0x7fffffff;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> priceArray[i][0] >> priceArray[i][1] >> priceArray[i][2];
    }

    memoizationArray[0][0] = priceArray[0][0];
    memoizationArray[0][1] = priceArray[0][1];
    memoizationArray[0][2] = priceArray[0][2];

    for (int i = 1; i < N; ++i)
    {
        memoizationArray[i][0] = min(memoizationArray[i - 1][1], memoizationArray[i - 1][2]) + priceArray[i][0];
        memoizationArray[i][1] = min(memoizationArray[i - 1][0], memoizationArray[i - 1][2]) + priceArray[i][1];
        memoizationArray[i][2] = min(memoizationArray[i - 1][0], memoizationArray[i - 1][1]) + priceArray[i][2];
    }

    minPrice = min({ memoizationArray[N - 1][0], memoizationArray[N - 1][1], memoizationArray[N - 1][2] });
    cout << minPrice << '\n';
    return 0;
}