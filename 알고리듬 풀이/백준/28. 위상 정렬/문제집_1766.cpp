/**
 * 백준 문제집_1766
 * N개의 문제로 구성되있는 문제집이 있다.
 * 문제 순서는 난이도 순서로 정렬되어있다 -> asc
 * 문제를 풀이하는데 조건이 있다.
 *      1. N개의 문제는 모두 풀어야 한다.
 *      2. 먼저 푸는 것이 좋은 문제가 있는 문제는, 
 *         먼저 푸는 것이 좋은 문제를 반드시 먼저 풀어야 한다.
 *      3. 가능하면 쉬운 문제부터 풀어야 한다.
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 32,001                       *
 * 1 <= M < 100,001                      *
 * M is CompairCaseSize                  *
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
#include <vector>
#include <queue>

using namespace std;

static const int MAX_N_SIZE = 32001;
static const int MAX_COMPAIR_SIZE = 100001;

static int N, M;

static int result[MAX_N_SIZE] = { 0 };
static vector<int> problems[MAX_N_SIZE];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    vector<int> inDegree(N + 1, 0);

    // 문제 번호간 연결 매핑
    for (int i = 0; i < M; ++i)
    {
        int before, after;
        cin >> before >> after;
        problems[before].push_back(after);
        ++inDegree[after];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; ++i)
    {
        if (inDegree[i] == 0)
        {
            pq.push(i);
        }
    }

    int index = 1;
    while (!pq.empty())
    {
        int u = pq.top();
        pq.pop();

        result[index++] = u;

        for (int j = 0; j < (int)problems[u].size(); ++j)
        {
            int v = problems[u][j];
            --inDegree[v];
            if (inDegree[v] == 0)
            {
                pq.push(v);
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}