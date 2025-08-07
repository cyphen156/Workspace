/**
 * 백준 쿼드트리_1992
 * 이차원 배열에서 데이터들이 한곳에 많이 몰려있다면 쿼드트리라는 데이터 구조를 통해 압축하여 표현할 수 있다.
 * 사각형 압축이 진행되며, 앞서 풀었던 4분할 분할 정복 기법이 사용된다. 
 * (0, (0011)(0(0111)01), 1)
 * 
 * 제한사항
 *****************************************
 * N is a 2 ** K                         *
 * 1 <= N < 65                           *
 * 0 is white (false)                    *
 * 1 is black (true)                     *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 10분
 */


#include <iostream>
#define MAX_SIZE 65

using namespace std;

static int board[MAX_SIZE][MAX_SIZE] = { 0 };
static int N;

void DivideAndConquer(int startX, int startY, int checkSize);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        
        for (int j = 0; j < N; ++j)
        {
            board[i][j] = str[j] - '0';
        }
    }

    DivideAndConquer(0, 0, N);
    cout << '\n';
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
        cout << base;
    }
    else 
    {
        int newCheckSize = checkSize / 2;
        cout << "(";
        DivideAndConquer(startX, startY, newCheckSize);
        DivideAndConquer(startX, startY + newCheckSize, newCheckSize);
        DivideAndConquer(startX + newCheckSize, startY, newCheckSize);
        DivideAndConquer(startX + newCheckSize, startY + newCheckSize, newCheckSize);
        cout << ")";
    }
};
