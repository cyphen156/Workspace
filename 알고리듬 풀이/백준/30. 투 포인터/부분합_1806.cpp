/**
 * 백준 부분합_1806
 * 10,000이하의 자연수로 이루어진 수열에서 
 * 연속된 수들의 부분합중 S이상이 되는 것 중 
 * 길이가 가장 짧은 것을 구하라.
 * 만약 합을 만드는 것이 불가능 하다면 0을 출력한다.
 * 누산합 개념을 사용할 수 있다.
 * 반례 찾는게 좀 걸렷다. 
 * Ex) 길이 1일때 또한 체크할 수 있어야 한다.
 * 1개 원소로 부분합을 만들 수 있는 경우
 * 
 * 
 * 제한사항
 *****************************************
 * 10 <= N < 100,000                     *
 * 1 <= S < 100,000,001                  *
 * 1 <= value < 10,001                   *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 3 + 30분
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int MAX_N_SIZE = 100001;

static const int INF = 100000001;

static int N, S, cnt = INF;

vector<int> arr;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    cin >> S;

    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    int left = 0;
    int right = 0;

    int sum = arr[left];
    while (right < N)
    {
        if (left != right)
        {
            sum += arr[right];
        }

        // 만약 부분합이 맞다면
        while (sum >= S)
        {
            // 길이가 최소인지 먼저 체크
            // 만약 이번 체크가 더 짧다면 갱신
            int length = right - left + 1;
            if (length < cnt)
            {
                cnt = length;
            } 

            sum -= arr[left++];
        }
        ++right;
    }

    if (cnt == INF)
    {
        cnt = 0;
    }
    cout << cnt << '\n';
    return 0;
}