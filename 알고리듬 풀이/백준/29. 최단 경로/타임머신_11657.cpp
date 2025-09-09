/**
 * 백준 타임머신_11657
 * N개의 도시 (정점)
 * 한 도시에서 출발(Start)하여 다른 도시에 도착(End)하는 버스(Edge) M개(간선 수)
 * 이동 비용이 양수가 아닐 수 있다 == 음수와 0이 허용된다.
 * 
 * 출력
 * // 1. 순환 발생(음의 무한대)
 * 만약 1번 도시에서 출발해 어떤 도시로 가는 과정에서 시간을 무한히 오래 전으로 되돌릴 수 있다면 첫째 줄에 -1을 출력한다.
 * // 2. 정상 출력
 * 그렇지 않다면 N-1개 줄에 걸쳐 각 줄에 1번 도시에서 출발해 2번 도시, 3번 도시, ..., N번 도시로 가는 가장 빠른 시간을 순서대로 출력한다.
 * // 3. 도착 못함(양의 무한대)
 * 만약 해당 도시로 가는 경로가 없다면 대신 -1을 출력한다.
 * 
 * HINT 
 * 벨만-포드 알고리즘
 * 음수 가중값이 존재할 경우 반드시 순환 문제 발생 체크 필요
 * 
 * 제한사항
 *****************************************
 * 1<= N < 501                           *
 * 1 <= M < 6,001                        *
 * A is Start, B is End, C is Weight     *
 * 1 <= A, B < N + 1                     *
 * -10,000 <= C < 10,001                 *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 50분
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

static const long long int INF = 0x7fffffffffffffffLL;

static int N, M;

vector<vector<pair<int, long long>>> graph;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    // 정점
    graph.assign(N + 1, {  });
    for (int i = 0; i < M; ++i)
    {
        int A, B;
        long long int C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
    }

    vector<long long int> dist(N + 1, INF);

    // 시작점 초기화(1번 도시)
    dist[1] = 0;

    // 모든 도시까지의 최단거리 구하기
    for (int i = 0; i < N; ++i)
    {
        bool isUpdated = false;

        for (int j = 1; j <= N; ++j)
        {
            if (dist[j] == INF)
            {
                continue;
            }
            for (int k = 0; k < graph[j].size(); ++k)
            {
                int v = graph[j][k].first;
                long long w = graph[j][k].second;

                if (dist[v] > dist[j] + w)
                {
                    dist[v] = dist[j] + w;
                    isUpdated = true;
                }
            }
        }

        if (!isUpdated)
        {
            break;
        }
    }
    
    // CASE 1.
    // 음수 싸이클 발생 지점 걸러내기
    for (int i = 1; i <= N; ++i)
    {
        if (dist[i] == INF)
        {
            continue;
        }
        for (int j = 0; j < static_cast<int>(graph[i].size()); ++j)
        {
            int to = graph[i][j].first;
            long long weight = graph[i][j].second;

            if (dist[to] > dist[i] + weight)
            {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    // 출력
    for (int i = 2; i <= N; ++i)
    {
        if (dist[i] == INF)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << dist[i] << '\n';
        }
    }
    return 0;
}