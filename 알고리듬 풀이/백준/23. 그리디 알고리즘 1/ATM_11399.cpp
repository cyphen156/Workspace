/**
 * 백준 ATM_11399
 * 1대의 ATM을 N명이 사용하려 한다.
 * 각각 번호표가 있으며, 인출하는데 걸리는 시간은 Pi분이다.
 * 모든 사람의 대기 시간의 합이 최소가 되도록 하는 순서를 만들고, 대기시간을 출력하라.
 * ==> SJF 스케쥴링 기법
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 1,001                        *
 * 1 <= Pi < 1,001                       *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 15분
 */


#include <iostream>
#include <algorithm>
#define MAX_SIZE 1001

using namespace std;

static int N;
static int waitTimes[MAX_SIZE] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> waitTimes[i];
    }

    sort(waitTimes, waitTimes + N);

    int totalWaitTime = 0;
    int sum = 0;

    for (int i = 0; i < N; ++i)
    {
        sum += waitTimes[i];    // 1 + 2 + 3
        totalWaitTime += sum;   // 1 + (1 + 2) + (1 + 2 + 3) 
    }

    cout << totalWaitTime << '\n';
    return 0;
}