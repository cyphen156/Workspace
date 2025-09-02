/**
 * 백준 토마토_7569_3D
 * 이 전 문제인 토마토를 응용해 3차원으로 만든 문제.
 * 토마토가 익는 방향이 추가적으로 상/하로 영향을 준다. 
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
 * 1 <= H <101                           *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 5분
 */


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

struct Cell
{
    int h, y, x;
};

static const int dh[6] = { 1, -1, 0, 0, 0, 0 };
static const int dy[6] = { 0, 0, 1, -1, 0, 0 };
static const int dx[6] = { 0, 0, 0, 0, 1, -1 };

static int M, N, H;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N >> H;
    
    vector<vector<vector<int>>> grid(H, vector<vector<int>>(N, vector<int>(M, 0)));
    queue<Cell> q;
    
    int unripe = 0;
    for (int k = 0; k < H; ++k)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j  = 0; j < M; ++j)
            {
                cin >> grid[k][i][j];
                if (grid[k][i][j] == 1)
                {
                    q.push(Cell{ k, i, j });
                }
                else if (grid[k][i][j] == 0)
                {
                    ++unripe;
                }
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
            Cell current = q.front();
            q.pop();

            int h = current.h;
            int y = current.y;
            int x = current.x;

            for (int k = 0; k < 6; ++k)
            {
                int nh = h + dh[k];
                int ny = y + dy[k];
                int nx = x + dx[k];

                if (ny < 0 || ny >= N 
                    || nx < 0 || nx >= M
                    || nh < 0 || nh >= H)
                {
                    continue;
                }
                if (grid[nh][ny][nx] != 0)
                {
                    continue;
                }
                grid[nh][ny][nx] = 1;
                --unripe;
                q.push({ nh, ny, nx });
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
