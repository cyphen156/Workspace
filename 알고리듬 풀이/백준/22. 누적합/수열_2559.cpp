/**
 * 백준 수열_2559
 * 정수의 수열이 주어질 때 연속적인 몇일 동안의 온도 합이 가장 큰 값을 알아보고자 한다.
 * 누산 배열을 사용하여 값을 구해라.
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

#define MAX_SIZE 100001

using namespace std;

static int N, K; 

static int temperatures[MAX_SIZE] = { 0 };      // day is index
static int accumulationdArray[MAX_SIZE] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 입력부
    cin >> N >> K;

    for (int i = 1; i <= N; ++i)
    {
        cin >> temperatures[i];
        accumulationdArray[i] = accumulationdArray[i - 1] + temperatures[i];
    }

    int maxSum = 2 * MAX_SIZE;
    maxSum *= -1;

    for (int i = 0;i <= N - K; ++i)
    {
        int temp = accumulationdArray[i + K] - accumulationdArray[i];
        if (temp > maxSum)
        {
            maxSum = temp;
        }
    }

    cout << maxSum << '\n';
    return 0;
}