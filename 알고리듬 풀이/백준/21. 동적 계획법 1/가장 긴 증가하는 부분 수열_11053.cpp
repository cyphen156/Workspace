/**
 * 백준 가장 긴 증가하는 부분 수열_11053
 * 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
 * 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우
 * 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 1,000                        *
 * 0 < Value <= 1,000                    *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 15분
 */


#include <iostream>
#include <algorithm>

#define MAX_SIZE 1000

using namespace std;

static int numberArray[MAX_SIZE] = { 0 };
static int maxLengthMemoizationArray[MAX_SIZE] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> numberArray[i];
        maxLengthMemoizationArray[i] = 1;
    }
    
    int maxLength = 1;

    for (int i = 0; i < N; ++i)
    {
        for (int j = i; j < N; ++j)
        {
            if (numberArray[i] < numberArray[j])
            {
                maxLengthMemoizationArray[j] = max(
                    maxLengthMemoizationArray[j],
                    maxLengthMemoizationArray[i] + 1
                );
            }
        }
        maxLength = max(maxLength, maxLengthMemoizationArray[i]);
    }
    
    cout << maxLength << '\n';    return 0;
}