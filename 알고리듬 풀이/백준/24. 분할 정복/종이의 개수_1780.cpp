/**
 * 백준 종이의 개수_1780
 * 세가지 데이터를 갖을 수 있는 N x N크기의 행렬이 있다. (-1 <= value < 2)
 * 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
 * (1)이 아닌 경우에는 종이를 같은 크기의 종이 9개로 자르고,
 * 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
 * ==> 4분할이 아닌 3 x 3 == 9 분할 정복
 * 출력은 -1로 채워진 종이의 갯수, 0으로 채워진 종이의 갯수,
 * 1로 채워진 종이의 갯수를 순차적으로 한줄씩 출력한다.
 * 
 * 제한사항
 *****************************************
 * -1 <= value < 2                       *
 * N is a 3 ** K                         *
 * 0 <= K < 8                            *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 3 + 5분
 */

#include <iostream>

#define MAX_SIZE 2187

using namespace std;

static int board[MAX_SIZE][MAX_SIZE] = { 0 };
static int N;

void DivideAndConquer(int startX, int startY, int checkSize);

static int cnt1 = 0, cnt2 = 0, cnt3 = 0;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
        }
    }

    DivideAndConquer(0, 0, N);

    cout << cnt1 << '\n'
        << cnt2 << '\n'
        << cnt3 << '\n';

    return 0;
}

void DivideAndConquer(int startX, int startY, int checkSize)
{
    int base = board[startX][startY];
    bool isSame = true;

    for (int i = 0; i < checkSize; ++i)
    {
        for (int j = 0; j < checkSize; ++j)
        {
            if (board[startX + i][startY + j] != base)
            {
                isSame = false;
                break;
            }
        }
        if (!isSame)
        {
            break;
        }
    }

    if (isSame)
    {
        if (base == -1)
        {
            ++cnt1;
        }
        else if (base == 0)
        {
            ++cnt2;
        }
        else 
        {
            ++cnt3;
        }
    }
    else 
    {
        int newCheckSize = checkSize / 3;
        // 1, 2, 3
        DivideAndConquer(startX, startY, newCheckSize);
        DivideAndConquer(startX, startY + newCheckSize, newCheckSize);
        DivideAndConquer(startX, startY + 2 * newCheckSize, newCheckSize);
        // 4, 5, 6
        DivideAndConquer(startX + newCheckSize, startY, newCheckSize);
        DivideAndConquer(startX + newCheckSize, startY + newCheckSize, newCheckSize);
        DivideAndConquer(startX + newCheckSize, startY + 2 * newCheckSize, newCheckSize);
        // 7, 8, 9
        DivideAndConquer(startX + 2 * newCheckSize, startY, newCheckSize);
        DivideAndConquer(startX + 2 * newCheckSize, startY + newCheckSize, newCheckSize);
        DivideAndConquer(startX + 2 * newCheckSize, startY + 2 * newCheckSize, newCheckSize);
    }
};
