/**
 * 백준 포도주 시식_2156
 * 문제를 간단히 요약하면 다음과 같다.
 * 1. 하나를 선택하면 그 칸은 다시 선택할 수 없다.
 * 2. 연속으로 세 칸을 순서대로 선택할 수 없다.
 * 각 칸에 있는 값의 가치가 서로 다를 때, N개의 포도주에서  최대한 많은 양의 포도주를 마실 수 있도록 선택하라.
 * Hint.
 * 1칸 또는 두칸을 연속해서 선택 할 수 있다.
 *
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 10,000                       *
 * 0 <= Value <= 1,000                   *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 25분
 */


#include <iostream>
#include <algorithm>

#define MAX_SIZE 10000

using namespace std;

static int wineValues[MAX_SIZE] = { 0 };
static int memoizationArray[MAX_SIZE] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> wineValues[i];
    }

    memoizationArray[0] = wineValues[0];

    if (N >= 2)
    {
        memoizationArray[1] = wineValues[0] + wineValues[1];
    }

    if (N >= 3)
    {
        memoizationArray[2] = max({ 
            memoizationArray[1],           // 1 + 1 + 0 == wineValues[0] + wineValues[1]
            wineValues[0] + wineValues[2], // 1 + 0 + 1
            wineValues[1] + wineValues[2]  // 0 + 1 + 1
        });
    }

    for (int i = 2; i < N; ++i)
    {
        memoizationArray[i] = max({
            memoizationArray[i - 1],
            memoizationArray[i - 2] + wineValues[i],
            memoizationArray[i - 3] + wineValues[i - 1] + wineValues[i]
        });
    }

    cout << memoizationArray[N - 1] << '\n';
    return 0;
}