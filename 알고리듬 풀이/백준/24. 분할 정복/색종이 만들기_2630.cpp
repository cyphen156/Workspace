/**
 * 백준 색종이 만들기_2630
 * 기본적인 Divide & Concuer, 이미 정렬 기법중 머지 소트를 사용했으므로 비슷한 로직을 사용한다.
 * 다음과 같은 종이가 있을 때 두번째 그림과 같이 사각형을 나누고, 잘린 파란색과 하얀색 종이의 갯수를 각각 구하라
 * 
 * 제한사항
 *****************************************
 * N == 2^K                              *
 * 1 <= K < 8                            *
 * if (input == 0) value is white        *
 * else value is blue                    *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 3 + 30분
 */


#include <iostream>

#define MAX_SIZE 0b10000000

using namespace std;

static int page[MAX_SIZE][MAX_SIZE] = { 0 };
static int N;
static int whiteCount = 0;
static int blueCount = 0;

void DivideAndConcuer(int x, int y, int size);

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
            cin >> page[i][j];
        }
    }

    DivideAndConcuer(0, 0, N);

    cout << whiteCount << '\n' 
        << blueCount << '\n';
    return 0;
}

void DivideAndConcuer(int x, int y, int size)
{
    int color = page[x][y];
    bool isSquare = true;

    for (int i = x; i < x + size; ++i)
    {
        for (int j = y; j < y + size; ++j)
        {
            if (page[i][j] != color)
            {
                isSquare = false;
                break;
            }
        }
        if (!isSquare)
        {
            break;
        } 
    }

    if (isSquare)
    {
        if (color == 0) 
        {
            ++whiteCount;
        }
        else 
        {
            ++blueCount;
        }
        return;
    }

    int half = size / 2;
    DivideAndConcuer(x, y, half);                     // 1사분면
    DivideAndConcuer(x, y + half, half);              // 2사분면
    DivideAndConcuer(x + half, y, half);              // 3사분면
    DivideAndConcuer(x + half, y + half, half);       // 4사분면
}