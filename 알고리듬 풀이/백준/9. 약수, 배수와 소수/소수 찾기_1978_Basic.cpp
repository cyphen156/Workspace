/**
 * 백준 소수 찾기_1978_Basic
 * N이하의 소수를 모두 찾기
 * 베이직 기법으로 찾아본 후 시간을 단축할 수 있는 방법을 고려해본다.
 * 
 * 제한사항
 *****************************************
 * 0 < Input <= 100                      *
 * 0 < Number <= 1,000                   *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 10분
 */


#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int checkPrimal[1001] = { 1, 1, 0 };
    int cnt = 0;
    // 0과 1은 소수가 아니다.
    for (int i = 2; i < 1001; ++i)
    {
        for (int j = 2; j < i; ++j)
        {
            if ((i % j) == 0)
            {
                // 소수가 아니다
                checkPrimal[i] = 1;
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        if (checkPrimal[input] == 0)
        {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}