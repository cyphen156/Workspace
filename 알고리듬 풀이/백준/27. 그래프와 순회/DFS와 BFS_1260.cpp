/**
 * 백준 DFS와 BFS_1260
 * 간단하게 탐색한 결과를 출력하는 프로그램
 * 단, 1:1이 아닌 다 : 다 관계로 연결될 수 있어 간선이 여러개 존재할 수 잇다.
 * 이 경우 정점 번호가 작은 것을 먼저 방문한다.
 * 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 1,001                        *
 * 1 <= M < 10,001                       *
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
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

static const int MAX_VERTICIES_COUNT = 1001;
static const int MAX_EDGE_COUNT = 10001;

using namespace std;

static int N, M, start;
static vector<vector<int>> verticies;
void DFS(int start);
void BFS(int start);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> start;
    verticies.assign(N + 1, vector<int>());

    for (int i = 0; i < M; ++i)
    {
        int u, v;

        cin >> u >> v;
        verticies[u].push_back(v);
        verticies[v].push_back(u);
    }

    // sort edge to other
    for (int i = 1; i <= N; ++i)
    {
        sort(verticies[i].begin(), verticies[i].end());
    }

    DFS(start);
    cout << '\n';

    BFS(start);
    cout << '\n';
    
    return 0;
}

void DFS(int start)
{
    // clear
    bool isVisited[MAX_VERTICIES_COUNT] = { 0 };

    stack<int> stack;
    // vector<int> printQ;

    stack.push(start);

    while (stack.empty() != true)
    {
        int current = stack.top();
        stack.pop();

        if (isVisited[current] != 0)
        {
            continue;
        }

        isVisited[current] = 1;
        // printQ.push_back(next);
        cout << current << ' ';

        for (int i = static_cast<int>(verticies[current].size()) - 1; i >= 0; --i)
        {
            int next = verticies[current][i];
            if (isVisited[next] == 0)
            {
                stack.push(next);
            }
        }
    }

    // print
    // for (int i = 0; i < N; ++i)
    // {
    //     cout << printQ[i] << ' ';
    // }
}

void BFS(int start)
{
    // clear
    bool isVisited[MAX_VERTICIES_COUNT] = { 0 };

    queue<int> q;
    q.push(start);
    
    isVisited[start] = 1;

    while (q.empty() == 0)
    {
        int current = q.front();
        q.pop();

        cout << current << ' ';

        for (int i = 0; i < static_cast<int>(verticies[current].size()); ++i)
        {
            int next = verticies[current][i];
            if (isVisited[next] == 0)
            {
                isVisited[next] = 1;
                q.push(next);
            }
        }
    }

    // print
    // for (int i = 0; i < N; ++i)
    // {
    //     cout << isVisited[i] << ' ';
    // }
}