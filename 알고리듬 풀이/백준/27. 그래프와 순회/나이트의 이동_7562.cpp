/**
 * 백준 나이트의 이동_7562
 * 체스에서 나이트의 이동을 생각해보라.
 * 다음과 같이 팔방을 움직일 수 있다.
 * 나이트가 현재 위치에서 시작하여 특정 위치로 도달해야 할 때 최소 이동 횟수를 구하라.
 * 
 * 
 * 제한사항
 *****************************************
 * Test T                                *
 * 4 <= L < 301                          *
 * L X L SIZE Board                      *
 * 0 <= (i, j) < L                       *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1+ 20분
 */


#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

static const int MAX_SIZE = 301;
static const pair<int, int> MOVE[8] = 
                {
                    {1, 2}, {2, 1},      // 1사분면
                    {-1, 2}, {-2, 1},    // 2사분면
                    {-1, -2}, {-2, -1},  // 3사분면
                    {1, -2}, {2, -1}     // 4사분면
                };
            
static int T, L;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> L;

        pair<int, int> from, to;
        cin >> from.first >> from.second;
        cin >> to.first >> to.second;

        if (from == to)
        {
            cout << 0 << '\n';
            continue;
        }

        vector<vector<int>> dist(L, vector<int>(L, -1));
        queue<pair<int, int>> q;

        dist[from.first][from.second] = 0;
        q.push(from);

        bool done = false;

        while (!q.empty() && !done)
        {
            pair<int, int> current = q.front();
            q.pop();

            for (int k = 0; k < 8; ++k)
            {
                int nr = current.first  + MOVE[k].first;
                int nc = current.second + MOVE[k].second;

                if (nr < 0 || nr >= L || nc < 0 || nc >= L)
                {
                    continue;
                }
                if (dist[nr][nc] != -1)
                {
                    continue;
                }

                dist[nr][nc] = dist[current.first][current.second] + 1;

                if (nr == to.first && nc == to.second)
                {
                    cout << dist[nr][nc] << '\n';
                    done = true;
                    break;
                }

                q.push({ nr, nc });
            }
        }
    }

    return 0;
}