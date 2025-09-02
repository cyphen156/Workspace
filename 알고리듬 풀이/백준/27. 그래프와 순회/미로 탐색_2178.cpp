/**
 * 백준 미로 탐색_2178
 * N X M 크기의 배열에서 미로 탈출구 찾기
 * 0은 이동할 수 없는 칸
 * 1은 이동할 수 있는 칸
 * 시작은 1행 1열
 * 끝은 N행 M열
 * 칸을 셀 때에는 시작 위치와 도착 위치를 포함한다.
 * 
 * 
 * 제한사항
 *****************************************
 * 2 <= N, M < 101                       *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 3 + 10분
 */


#include <iostream>
#include <queue>

using namespace std;

static const int MAX_SIZE = 100;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

static int N, M;

static char matrix[MAX_SIZE][MAX_SIZE] = { 0 };
static bool isVisited[MAX_SIZE][MAX_SIZE] = { 0 };
static int distanceArray[MAX_SIZE][MAX_SIZE] = { 0 };

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

    queue<pair<int,int>> q;

    q.push({0, 0});
    isVisited[0][0] = true;
    distanceArray[0][0] = 1;

    while(q.empty() != true)
    {
        pair<int, int> current = q.front();
        q.pop();

        if (current.first == N-1 && current.second == M-1)
        {
            break;
        }

        for (int k = 0; k < 4; ++k)
        {
            int ny = current.first + dy[k];
            int nx = current.second + dx[k];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) 
            {
                continue;
            }

            if (matrix[ny][nx] != '1') 
            {
                continue;
            }

            if (isVisited[ny][nx])
            {
                continue;
            } 

            isVisited[ny][nx] = true;
            distanceArray[ny][nx] = distanceArray[current.first][current.second] + 1;
            q.push({ny, nx});
        }
    }

    cout << distanceArray[N - 1][M - 1] << '\n';
    return 0;
}