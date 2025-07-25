/**
 * 백준 연속합_1912
 * N개의 정수로 이루어진 수열이 있다. 
 * 연속된 몇 개의 수를 선택하여 구할 수 있는 합 중 가장 큰 합을 구하라
 * 
 * 몇 개의 수를 선택할지는 알 수 없다. 그냥 가장 큰 합을 구하면 된다.
 * 1개부터 순차적으로 길이를 늘려가면서 계산 할 수 있다.
 * 인덱스 밀어내기를 통해 순차합을 구해 각 길이마다 최대 합을 구해 메모할 수 있다.
 * ==> Kadane’s Algorithm (카데인 알고리즘)
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 100,000                      *
 * -1,001 < Input <= 1,000               *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 5분
 */


#include <iostream>

#define MAX_SIZE 100000
#define MIN_VALUE -1001

static int N;
static int maxSum = MIN_VALUE;

static int inputs[MAX_SIZE] = { 0 };
static int memoizationArray[MAX_SIZE] = { 0 };

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> inputs[i];
    }

    memoizationArray[0] = inputs[0];
    maxSum = inputs[0];

    for (int i = 1; i < N; ++i)
    {
        memoizationArray[i] = max(inputs[i], memoizationArray[i - 1] + inputs[i]);
        maxSum = max(maxSum, memoizationArray[i]);
    }

    cout << maxSum << '\n';
    return 0;
}