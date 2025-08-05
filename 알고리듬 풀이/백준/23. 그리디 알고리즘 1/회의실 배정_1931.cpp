/**
 * 백준 회의실 배정_1931
 * 1개의 방, N개의 회의를 가지고 회의실 사용 표순서를 만드려고 한다.
 * 각 회의는 시작 시간과 끝나는 시간이 존재할 때, 
 * 겹치지 않으면서 최대한 많은 회의를 진행 할 수 있도록 표를 구성한다.
 * 각 회의는 원자성을 가지고 있고,
 * 서로 다른 회의의 시작 시간과 끝나는 시간은 겹쳐도 된다.
 * 시작 시간과 끝나는 시간이 같은 회의도 있을 수 있다. 
 * 
 * 제한사항
 *********************************************
 * 1 <= N < 100,001                          *
 * 0 <= startTime <= EndTime < 2^31 - 1 (int)*
 *********************************************
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
#include <vector>
#include <algorithm>

using namespace std;

static int N;
static vector<pair<int, int>> times;

bool Compare(const pair<int, int>&first, const pair<int, int>&second);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    times.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        int start, end;
        cin >> start >> end;
        times.push_back({start, end});
    }

    sort(times.begin(), times.end(), Compare);
    
    int cnt = 0;
    
    int last = 0;
    for (int i = 0; i < N; ++i)
    {
        if (times[i].first >= last)
        {
            cnt++;
            last = times[i].second;
        }
    }

    cout << cnt << '\n';
    return 0;
}

bool Compare(const pair<int, int>&first, const pair<int, int>&second)
{
    if (first.second == second.second)
    {
        // 종료 시간이 같다면 시작시간이 더 나중에 있는걸 기준으로 정렬하기 위함
        // => 회의 진행 시간이 짧다는 것을 의미하기 때문에
        return first.first < second.first;
    }
    return first.second < second.second;
}
