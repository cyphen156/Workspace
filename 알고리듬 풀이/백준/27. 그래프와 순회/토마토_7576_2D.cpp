/**
 * 백준 토마토_7576_2D
 * 유기농 배추 문제와 유사한 문제
 * 익은 토마토는 사방면으로 인접한 토마토에게 영향을 주어 똑같이 익힌다.
 * 시작 위치가 주어졌을 때 모든 토마토가 전부 익게 되는지 최소 일 수를 구하라.
 * 익은 토마토의 위치가 여러곳에 퍼져 있을 수 있다.
 * -> 최소 일수를 갱신해야 한다. 
 * 
 * 제한사항
 *****************************************
 * 2 <= N, M < 1,001                     *
 * 1 = 익은 토마토                        *
 * 0 = 익지 않은 토마토                   *
 * -1 = 토마토가 없는 칸                  *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 30분
 */


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

static const int dx[4] = { 0, 0, 1, -1 };
static const int dy[4] = { 1, -1, 0, 0 };

static int M, N;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N;
    
    vector<vector<int>> grid(N, vector<int>(M, 0));
    queue<pair<int,int>> q;
    
    int unripe = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j  = 0; j < M; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
            {
                q.push({i, j});
            }
            else if (grid[i][j] == 0)
            {
                ++unripe;
            }
        }
    }

    if (unripe == 0) 
    {
        cout << 0 << '\n';
        return 0;
    }

    int day = 0;

    while (!q.empty() && unripe > 0)
    {
        int qSize = q.size();

        for (int i = 0; i < qSize; ++i)
        {
            pair<int, int> current = q.front();
            q.pop();

            int y = current.first;
            int x = current.second;

            for (int k = 0; k < 4; ++k)
            {
                int ny = y + dy[k];
                int nx = x + dx[k];

                if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                {
                    continue;
                }
                if (grid[ny][nx] != 0)
                {
                    continue;
                }
                grid[ny][nx] = 1;
                --unripe;
                q.push({ ny, nx });
            }
        }
        day++;
    }

    if (unripe != 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << day << '\n';
    }
    return 0;
}
