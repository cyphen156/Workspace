/**
 * 백준 숨바꼭질 3_13549
 * 그래프와 순회 섹터에서 풀었던 문제다. 
 * 수빈이(N)와 동생(K)이
 * 직선상의 서로 다른 위치에 존재한다.
 * 수빈이는 위치를 +-1 또는 현재의 X2배의 위치로 움직일 수 있다.
 * +-1의 경우 1초가 걸리고 X2의 경우 0초가 걸리는 가중값이 생겻다.
 * 수빈이가 동생을 찾을 수 있는 가장 빠른 시간을 구하라.
 * 
 * 제한사항
 *****************************************
 * 0 <= N, K < 100,001                   *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 3 + 15분
 */


#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

static const int MAX_SIZE = 100001;
static const int MAX_VALUE = 0x7fffffff;

static int N, K;

static vector<int> dist(MAX_SIZE, MAX_VALUE);

int Dijkstra(int start , int target);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;

    cout << Dijkstra(N, K) << '\n';
    return 0;
}

int Dijkstra(int start, int target)
{
    if (start >= target)
    {
        return start - target;
    }

    deque<int> deq;
    dist[start] = 0;
    deq.push_front(start);

    const int U = min(MAX_SIZE - 1, target * 2);

    while(!deq.empty())
    {
        int current = deq.front();
        deq.pop_front();

        if (current == target)
        {
            return dist[current];
        } 

        // 순간이동
        int nx = 2 * current;
        if (nx <= U && dist[nx] > dist[current])
        {
            dist[nx] = dist[current];
            deq.push_front(nx);
        }

        // 앞으로 한칸
        nx = current + 1;
        if (nx <= U && dist[nx] > dist[current] + 1 /*if dist[nx] is INF*/ )
        {
            dist[nx] = dist[current] + 1;
            deq.push_back(nx);
        }

        // 뒤로 한칸
        nx = current - 1;
        if (nx >= 0 && dist[nx] > dist[current] + 1)
        {
            dist[nx] = dist[current] + 1;
            deq.push_back(nx);
        }
    }

    return dist[target];
}