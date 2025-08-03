/**
 * 백준 수열_2559 _slidingWindow
 * 정수의 수열이 주어질 때 연속적인 몇일 동안의 온도 합이 가장 큰 값을 알아보고자 한다.
 * 누산 배열과 슬라이딩 윈도우를 사용하여 값을 구해라.
 * 
 * 제한사항
 *****************************************
 * N is TotalDays                        *
 * 1 < N <= 100,000                      *
 * K is ContinousDays                    *
 * 0 < K <= N                            *
 * -101 < temperature <= 100             *
 *****************************************
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

#define MAX_SIZE 100000

using namespace std;

static int N, K;
static int temperatures[MAX_SIZE];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> temperatures[i];
    }

    int slidingWindowSum = 0;
    for (int i = 0; i < K; ++i)
    {
        slidingWindowSum += temperatures[i];
    }

    int maxSum = slidingWindowSum;

    for (int i = K; i < N; ++i)
    {
        slidingWindowSum += temperatures[i];
        slidingWindowSum -= temperatures[i - K];
        maxSum = max(maxSum, slidingWindowSum);
    }

    cout << maxSum << '\n';
    return 0;
}