/**
 * 백준 소수 찾기_1978_Sieve of Eratosthenes
 * N이하의 소수를 모두 찾기
 * 에라토스테네스의 체로 소수인지 판볋한다.
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
#include <cmath>

#define SIZE 1001

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    // true is not Prime
    // default == false means Prime
    bool checkPrimal[SIZE] = {false};

    checkPrimal[0] = checkPrimal[1] = true;

    int cnt = 0;

    // 선제적 소수 판정
    for (int i = 2; i * i < 1001; ++i)
    {
        if (!checkPrimal[i])
        {
            for (int j = i*i; j < SIZE; j += i)
            {
                checkPrimal[j] = true;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        int input;

        cin  >> input;
        if (!checkPrimal[input])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}