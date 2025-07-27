/**
 * 백준 1로 만들기_1463
 * 자연수 X가 주어졌을 때, 최소한의 연산 횟수를 통해 1을 만들어라.
 * 다음 유사 코드를 확인하자. 
 * while (X != 1)
 * {
 *     if (N % 3 == 0) 
 *         than 
 *         N / 3
 *     else if (N % 2 == 0) 
 *         than 
 *         N / 2
 *     else
 *     	N--
 * }
 * 
 * 잘 생각해보면 연산경우는 항상 3가지 이다.
 * 1 뼤거나 2로 나누거나 3으로 나누거나
 * 4는 2로 나눈다 1 + 1회
 * 5는 1빼고 2로 2번 나눈다. 1 + 1 + 1회
 * 6은 3으로 나눈 후 2로 나눈다. 1 + 1회
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 1,000,000                    *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 30분
 */


#include <iostream>
#include <algorithm>

#define MAX_SIZE 1000001

using namespace std;

// 인덱스까지 최소 연산 횟수 저장 
static int memoizationArray[MAX_SIZE] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    int cnt = 0;

    memoizationArray[0] = memoizationArray[1] = 0;

    for (int i = 2; i <= N; ++i)
    {
        // i == (i - 1) + 1이기 때문에 
        // ++연산 한번 더한 것으로 이전 연산 + 1회를 항상 해로 갖을 수 있음
        memoizationArray[i] =  memoizationArray[i - 1] + 1;

        if (i % 2 == 0)
        {
            memoizationArray[i] = min(memoizationArray[i], memoizationArray[i / 2] + 1);
        }

        if (i % 3 == 0)
        {
            memoizationArray[i] = min(memoizationArray[i], memoizationArray[i / 3] + 1);
        }
    }
    cout << memoizationArray[N] << '\n';

    return 0;
}