/**
 * 백준 뱀과 사다리 게임_16928
 * 1~6크기 중 자유롭게 이동할 수 있다.
 * 10 X 10 크기의 보드 판에서 게임이 진행된다.
 * 만약 주사위를 굴려 이동한 칸이 보드판 크기인 100을 넘어간다면 이동할 수 없다.
 * 도착한 칸이 사다리라면 위로 올라간다 == +value;
 * 도착한 칸이 뱀이라면 따라서 내려간다 == -value;
 * 
 * 
 * 제한사항
 *****************************************
 * 1 <= N, M < 15                        *
 * Ladder moves from x to y              *
 * Snake movesfrom u to v                *
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
#include <queue>
#include <utility>

using namespace std;

static const int MAX_SIZE = 101;

static int N, M;

static int board[MAX_SIZE] = { 0 };
static int cnt[MAX_SIZE] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    // 자기 자신 위치
    for (int i = 1; i <= MAX_SIZE; ++i)
    {
        board[i] = i;
    }

    // ladder
    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;

        board[x] = y;
    }

    // snake
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;

        board[u] = v;
    }

    queue<int> q;

    q.push(1);
    cnt[1] = 1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        
        if (current == 100)
        {
            break;
        }

        for (int i = 1; i <= 6; ++i)
        {
            int candidate = current + i;    

            if (candidate > 100)
            {
                continue;
            }

            int next = board[candidate];

            if (cnt[next] == 0)
            {
                cnt[next] = cnt[current] + 1;
                q.push(next);
            }
        }
    };

    cout << cnt[100] - 1 << '\n';
    return 0;
}