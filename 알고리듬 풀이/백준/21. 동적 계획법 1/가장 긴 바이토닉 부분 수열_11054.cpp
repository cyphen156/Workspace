/**
 * 백준 가장 긴 바이토닉 부분 수열_11054
 * 바이토닉은 다음과 같은 규칙성을 갖는다.
 * Case1 1, 2, 3, 2, 1
 * Case2 1, 2, 3, 4
 * Case3 4, 3, 2, 1
 * 즉, Pivot을 기준으로 앞은 오름차순, 뒤는 내림차순으로 정렬되어 있거나, 
 * 중간에 정렬 기준이 깨지지 않는 상태를 갖는 수열을 말한다.
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
 * 1 + 10분
 */


#include <iostream>
#include <algorithm>

#define MAX_SIZE 1000

using namespace std;

static int numberArray[MAX_SIZE] = { 0 };
static int maxLengthByAsc[MAX_SIZE] = { 0 };
static int maxLengthByDesc[MAX_SIZE] = { 0 };

static int pivot = 0;

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
        maxLengthByAsc[i] = 1;
        maxLengthByDesc[i] = 1;

    }
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (numberArray[j] < numberArray[i])
            {
                maxLengthByAsc[i] = max(maxLengthByAsc[i], maxLengthByAsc[j] + 1);
            }
        }
    }
    
    for (int i = N - 1; i >= 0; --i)
    {
        for (int j = N - 1; j > i; --j)
        {
            if (numberArray[j] < numberArray[i])
            {
                maxLengthByDesc[i] = max(maxLengthByDesc[i], maxLengthByDesc[j] + 1);
            }
        }
    }

    int maxLength = 0;
    for (int i = 0; i < N; ++i)
    {
        int total = maxLengthByAsc[i] + maxLengthByDesc[i] - 1;
        maxLength = max(maxLength, total);
    }

    cout << maxLength << '\n';    
    return 0;
}