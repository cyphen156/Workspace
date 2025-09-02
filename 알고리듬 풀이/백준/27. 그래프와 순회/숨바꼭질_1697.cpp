/**
 * 백준 숨바꼭질_1697
 * 수빈이(N)와 동생(K)이
 * 직선상의 서로 다른 위치에 존재한다.
 * 수빈이는 위치를 +-1 또는 현재의 X2배의 위치로 움직일 수 있다.
 * 수빈이가 동생을 찾을 수 있는 가장 빠른 시간을 구하라.
 * 
 * 
 * 제한사항
 *****************************************
 * 0 <= N, K < 100,001                   *
 *****************************************
 *
 *
 *
 * 주의
 * 순간 이동시 절반의 위치로 이동하는 경우는 예시로 들지 않았다.
 * -> 항상 현재 위치의 2배로만 이동한다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 3 + 30분
 */


#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

static const int MAX_SIZE = 100001;

static int N, K;

static bool isVisited[MAX_SIZE] = { 0 };
static int dist[MAX_SIZE] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;

    // 만약 동생이 수빈이보다 뒤에 있는 경우
    // -1칸씩 움직이는 방법 외엔 
    // 이동 방법이 존재하지 않는다.
    if (K <= N)
    {
        cout << N-K << '\n';
        return 0;
    }
    else 
    {
        // 탐색 수행
        queue<int> q;
        isVisited[N] = true;
        dist[N] = 0;
        q.push(N);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            if (current == K)
            {
                cout << dist[current] << '\n';
                return 0;
            }

            int nx;
            // 뒤로 먼저 움직여보기
            nx = current - 1;
            if (nx >= 0 && !isVisited[nx])
            {
                isVisited[nx] = true;
                dist[nx] = dist[current] + 1;
                q.push(nx);
            }
            // 앞으로 움직여보기
            nx = current + 1;
            if (nx <= MAX_SIZE && !isVisited[nx])
            {
                isVisited[nx] = true;
                dist[nx] = dist[current] + 1;
                q.push(nx);
            }
            // 점프
            nx = 2 * current;
            if (nx <= MAX_SIZE && !isVisited[nx])
            {
                isVisited[nx] = true;
                dist[nx] = dist[current] + 1;
                q.push(nx);
            }
        }
    }
    return 0;
}