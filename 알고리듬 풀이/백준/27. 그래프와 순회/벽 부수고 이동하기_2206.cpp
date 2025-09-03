/**
 * 백준 벽 부수고 이동하기_2206
 * N X M 행렬로 표시되는 맵이 있다.
 * 사방면(상 하 좌 우)으로 이동한다.
 * (1, 1)에서 부터 시작하여 (N, M)까지 이동하는데 최단경로를 사용한다.
 * 벽을 최대 한 개까지 부술 수 있다.
 * 
 * 제한사항
 *****************************************
 * 1 <= N, M < 1,001                     *
 * 0은 이동 할 수 있는 곳                 *
 * 1은 이동 할수 없는 벽                  *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 3 + 60분
 */


#include <iostream>
#include <queue>
#include <utility>

using namespace std;

static const int MAX_SIZE = 1001;
static const int dy[4] = { -1, 1, 0, 0 };
static const int dx[4] = { 0, 0, -1, 1 };

static int N, M;

static char matrix[MAX_SIZE][MAX_SIZE];
static int normalCount[MAX_SIZE][MAX_SIZE] = { 0 };
static int isBrokenCount[MAX_SIZE][MAX_SIZE] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    queue<pair< pair<int, int>, bool>> q;    // y, x, isBroke
    normalCount[0][0] = 1;
    q.push({ {0, 0}, false});

    while(!q.empty())
    {
        pair<pair<int, int>, bool> current = q.front();
        q.pop();

        int y = current.first.first;
        int x = current.first.second;
        bool isBroken = current.second;

        if (y == N - 1 && x == M - 1) 
        {
            if (isBroken)
            {
                cout << isBrokenCount[y][x] << '\n';
            }
            else
            {
                cout << normalCount[y][x] << '\n';
            }            
            return 0;
        }

        for (int i = 0; i < 4; ++i)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            {
                continue;
            }

            if (matrix[ny][nx] == '0')
            {
                if (!isBroken) 
                {
                    if (normalCount[ny][nx] == 0) 
                    {
                        normalCount[ny][nx] = normalCount[y][x] + 1;
                        q.push({{ny, nx}, false});
                    }
                } 
                else 
                {
                    if (isBrokenCount[ny][nx] == 0) 
                    {
                        isBrokenCount[ny][nx] = isBrokenCount[y][x] + 1;
                        q.push({{ny, nx}, true});
                    }
                }
            }
            else
            {
                if (!isBroken && isBrokenCount[ny][nx] == 0)
                {
                    isBrokenCount[ny][nx] = normalCount[y][x] + 1;
                    q.push({{ny, nx}, true});
                }
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}