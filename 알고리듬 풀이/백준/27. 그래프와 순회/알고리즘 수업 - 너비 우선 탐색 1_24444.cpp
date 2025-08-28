/**
 * 백준 알고리즘 수업 - 너비 우선 탐색 1_24444
 * BFS 구현하기
 * 무방향 그래프를 준다. 
 * 의사 코드는 다음과 같다.
 * 이번엔 내 맘대로 안만들고 의사코드를 존중한다.
 * 
 * 
 **********************************************************************
 * bfs(V, E, R) {  # V : 정점 집합, E : 간선 집합, R : 시작 정점        *
 *     for each v ∈ V - {R}                                          *
 *         visited[v] <- NO;                                          *
 *     visited[R] <- YES;  # 시작 정점 R을 방문 했다고 표시한다.        *
 *     enqueue(Q, R);  # 큐 맨 뒤에 시작 정점 R을 추가한다.             *
 *     while (Q ≠ ∅) {                                               *
 *         u <- dequeue(Q);  # 큐 맨 앞쪽의 요소를 삭제한다.            *
 *         for each v ∈ E(u)  # E(u) : 정점 u의 인접 정점 집합.        *
 *                              (정점 번호를 오름차순으로 방문한다)      *
 *             if (visited[v] = NO) then {                            *
 *                 visited[v] <- YES;  # 정점 v를 방문 했다고 표시한다. *
 *                 enqueue(Q, v);  # 큐 맨 뒤에 정점 v를 추가한다.      *
 *             }                                                      *
 *     }                                                              *
* }                                                                   *
 **********************************************************************
 * 
 **********************************************************************
 * Input                                                              *
 * N, M, R                                                            *
 *                                                                    *
 * for (M)                                                            *
 * 	Edge = from u to v                                                *
 **********************************************************************
 *
 **********************************************************************
 * Output                                                             *
 * 첫째 줄부터 N개의 줄에 정수를 한 개씩 출력한다.                       *
 * i번째 줄에는 정점 i의 방문 순서를 출력한다.                           *
 * 시작 정점의 방문 순서는 1이다.                                       *
 * 시작 정점에서 방문할 수 없는 경우 0을 출력한다.                       *
 **********************************************************************
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
 * 1 + 15분
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

static vector<int> vertices;
static vector<vector<int>> edges;
static int isVisited[MAX_VERTICES_COUNT] = { 0 };

void BFS(const vector<int>& vertices
    , const vector<vector<int>>& edges
    , const int startVertices);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> R;

    vertices.reserve(N);
    edges.resize(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        vertices.push_back(i);
    }

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(edges[i].begin(), edges[i].end());
    }

    BFS(vertices, edges, R);

    for (int i = 1; i <= N; ++i)
    {
        cout << isVisited[i] << '\n';
    }
    return 0;
}

void BFS(const vector<int>& vertices
    , const vector<vector<int>>& edges
    , const int startVertices)
{
    // 의사 코드 그대로 명시적 초기화
    for (int i = 1; i <= N; ++i)
    {
        isVisited[i] = 0;
    }

    int cnt = 1;
    isVisited[startVertices] = cnt;

    queue<int> q;
    q.push(startVertices);
    while (q.empty() != true)
    {
        int u = q.front();
        q.pop();

        // i is v
        for (int v : edges[u])        
        {
            if (isVisited[v] == 0)
            {
                isVisited[v] = ++cnt;
                q.push(v);
            }
        }
    }
}