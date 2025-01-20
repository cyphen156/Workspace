/**
 * 백준 심화 1 킹, 퀸, 룩, 비숍, 나이트, 폰_3003
 * 
 * 하얀색 체스말이 일부가 많거나 모자라다. 갯수를 맞춰라
 * 
 * 제한사항
 *****************************************
 * King, Queen <= 1                      *
 * Rook, Bishop, Knight <= 2             *
 * Pawn <= 8                             *
 *****************************************
 * 
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 5분
 */


#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> black = {1, 1, 2, 2, 2, 8};
    vector<int> white;

    for (int i = 0; i < 6; ++i)
    {
        int input;

        cin >> input;
        white.push_back(input);
    }

    for (int i = 0; i < 6; ++i)
    {
        cout << black[i] - white[i] << " ";
    }
    return 0;
}