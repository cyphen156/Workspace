/**
 * 백준 체스판 다시 칠하기 2_25682
 * M X N 크기의 단위 정사각형 보드를 사용한다.
 * 이 보드를 잘라서 K X K 크기의 정사각형 체스판을 만든다고 할 때, 
 * 검정색과 흰색이 번갈아 나타나도록 == 인접한 노드가 같은 색이 되지 않도록
 * 보드를 다시 칠해야 한다.
 * 다시 칠하는 갯수가 최소가 되도록 구현하라.
 * 
 * 이차원 누산 합을 이용하여 계산한다.
 * 
 * 제한사항
 *****************************************
 * 1 <= N, M < 2001                      *
 * 1 <= K < min(N, M) + 1                *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 30분
 */


#include <iostream>

#define MAX_SIZE 2001

using namespace std;

static bool board[MAX_SIZE][MAX_SIZE] = { 0 };  // 0 == black, 1 == white
static int whitePrefix[MAX_SIZE][MAX_SIZE] = {0};

static int N, M, K;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;

    for (int i = 0; i < N; ++i)
    { 
        for (int j = 0; j < M; ++j)
        {
            char ch;
            cin >> ch;
            bool flag = false;

            if (ch == 'W')
            {
                flag = true;
            }

            board[i][j] = flag;
        }
    }

    // 누산합 계산
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            bool isWhite = ((i + j) % 2 == 0);  // 홀수칸은 흰색이라고 가정
            bool currentColor = board[i - 1][j - 1];
            int mismatch = (currentColor != isWhite);

            whitePrefix[i][j] = whitePrefix[i - 1][j] + whitePrefix[i][j - 1]
                              - whitePrefix[i - 1][j - 1] + mismatch;
        }
    }

    int maxCount = K * K;
    int cnt = maxCount;
    for (int i = K; i <= N; ++i)
    {
        for (int j = K; j <= M; ++j)
        {
            int x1 = i - K;
            int y1 = j - K;
            int x2 = i;
            int y2 = j;

            int whiteCount = whitePrefix[x2][y2] - whitePrefix[x1][y2] - whitePrefix[x2][y1] + whitePrefix[x1][y1];

            cnt = min(cnt, min(whiteCount, maxCount - whiteCount));
        }
    }
    cout << cnt << '\n';
    return 0;
}