/**
 * 백준 알고리즘 수업 - 깊이 우선 탐색 1_24480
 * DFS 구현하기 2
 * 무방향 그래프를 준다. 
 * 의사 코드는 다음과 같다.
 * 이전 문제와 다른 점은 오름차순이 아닌 내림차순으로 방문한다.
 * 
 * 
 *****************************************************************
 * dfs(V, E, R) {  # V : 정점 집합, E : 간선 집합, R : 시작 정점    *
 *     visited[R] <- YES;  # 시작 정점 R을 방문 했다고 표시한다.    *
 *     for each x ∈ E(R)  # E(R) : 정점 R의 인접 정점 집합.       *
 *                          (정점 번호를 내림차순으로 방문한다)     *
 *         if (visited[x] = NO) then dfs(V, E, x);               *
 * }                                                             *
 *****************************************************************
 * 
 *****************************************************************
 * Input                                                         *
 * N, M, R                                                       *
 *                                                               *
 * for (M)                                                       *
 * 	Edge = from u to v                                           *
 *****************************************************************
 *
 *****************************************************************
 * Output                                                        *
 * 첫째 줄부터 N개의 줄에 정수를 한 개씩 출력한다.                   *
 * i번째 줄에는 정점 i의 방문 순서를 출력한다.                      *
 * 시작 정점의 방문 순서는 1이다.                                  *
 * 시작 정점에서 방문할 수 없는 경우 0을 출력한다.                  *
 *****************************************************************
 * 
 * 제한사항
 *****************************************
 * 5 <= N < 100,001                      *
 * 1 <= M < 200,001                      *
 * 1 <= R < N + 1                        *
 * 1 <= u < v < N + 1                    *
 * u != v                                *
 * 모든 간선의 (u, v) 쌍의 값은 서로 다르다 *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 1분
 */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

static const int MAX_VERTICES_COUNT  =   100000 + 1;
static const int MAX_EDGE_COUNT     =   200000 + 1;

using namespace std;

static int N, M;
static int R;   // start

struct Node
{
    vector<int> edgeTo; // from this to index;
};

static int isVisited[MAX_VERTICES_COUNT] = { 0 };

bool Compair(const int left, const int right);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> R;

    Node* vertices = new Node[MAX_VERTICES_COUNT];

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        vertices[u].edgeTo.push_back(v);
        vertices[v].edgeTo.push_back(u);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(vertices[i].edgeTo.begin(), vertices[i].edgeTo.end(), Compair);
    }

    // DFS
    stack<int> stack;
    queue<int> resultQueue;
    int visitCount = 0;

    stack.push(R);

    while(stack.empty() != true)
    {
        int u = stack.top();
        stack.pop();

        // 방문 했다면 건너뛰기
        if (isVisited[u] != 0)
        {
            continue;
        }

        resultQueue.push(u);
        isVisited[u] = ++visitCount;

         for (int i = static_cast<int>(vertices[u].edgeTo.size()) - 1; i >= 0; --i)
        {
            int v = vertices[u].edgeTo[i];
            if (isVisited[v] == 0)
            {
                stack.push(v);
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        cout << isVisited[i] << '\n';
    }
    return 0;
}

bool Compair(const int left, const int right)
{
    return left > right;
}