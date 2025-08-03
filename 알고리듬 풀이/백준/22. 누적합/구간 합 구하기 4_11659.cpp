/**
 * 백준 구간 합 구하기 4_11659
 * N개의 수가 주어졌을 때 i부터 j까지 수의 합을 구하는 프로그램을 작성하라
 * 
 * 제한사항
 *****************************************
 * N is Numbers                          *
 * M is RepeatCount                      *
 * 0 < N, M <= 100,000                   *
 * 0 < Value <= 1,000                    *
 * 0 < i <=  j <= N                      *
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

static int N, M;
static int values[MAX_SIZE] = { 0 };            // 원본용 <= 사실 필요없음
static int accumulationArray[MAX_SIZE] = { 0 }; // 누산용

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 기본 입력부
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        cin >> values[i];
        accumulationArray[i] = accumulationArray[i - 1] + values[i];
    }

    for (int i = 0; i < M; ++i)
    {
        int startIndex, endIndex;

        cin >> startIndex >> endIndex;

        cout << accumulationArray[endIndex] - accumulationArray[startIndex - 1] << '\n';
    }

    return 0;
}