/**
 * 백준 색종이_2563
 * 100 * 100 크기의 정사각형 안에 10 * 10 크기의 종이를 여러장 겹쳐 놓을 때 합 넓이를 구해라
 * 
 * 제한사항
 *****************************************
 * 0 < Width, Height <= 100              *
 * 도화지 밖으로 튀어나가는 색종이는 없다   *
 * 0 < input Case <= 100                 *
 *****************************************
 *
 *
 *
 * 주의
 * 
 * 
 * 풀이시간 10분
 */


#include <iostream>

using namespace std;

int main(void)
{
    int input;
    int plain[100][100] = {0};
    int cnt = 0;

    cin >> input;
    for (int i = 0; i < input; ++i)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        
        for (int j = x; j < x+10; ++j)
        {
            for (int k = y; k < y+10; ++k)
            {
                if (plain[j][k] == 1)
                {
                    continue;
                }
                plain[j][k] = 1;
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}