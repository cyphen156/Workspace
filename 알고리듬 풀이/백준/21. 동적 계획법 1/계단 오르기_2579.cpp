/**
 * 백준 계단 오르기_2579
 * 다음과 같은 규칙이 있다. 이 조건을 지켜가면서 가장 높은 점수를 구하라.
 * 1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
 * 2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
 * 3. 마지막 도착 계단은 반드시 밟아야 한다.
 * 시각화 하면 다음과 같은 그림이 나온다.
 * 
 * 핵심 아이디어는 다음과 같다.
 * 
 * 제한사항
 *****************************************
 * 0 < stairsCount <= 300                *
 * 0 < value <= 10,000                   *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 20분
 */


#include <iostream>

using namespace std;

static int stairs[301] = { 0 };
static int memoizationArray[301] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; 
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> stairs[i];
    }

    memoizationArray[0] = stairs[0];
    if (N >= 2)
    {
        memoizationArray[1] = stairs[0] + stairs[1];
    }
    if (N >= 3)
    {
        memoizationArray[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
    }

    for (int i = 3; i < N; ++i)
    {
        memoizationArray[i] = max(memoizationArray[i-2], memoizationArray[i-3] + stairs[i-1]) + stairs[i];
    }

    cout << memoizationArray[N - 1] << '\n';

    return 0;
}