/**
 * 백준 피보나치 수 5_10870
 * 피보나치수 계산하기
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 20                           *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 0분
 */


#include <iostream>

using namespace std;

int Fibo(int value);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    cout << Fibo(N) << '\n';

    return 0;
}

int Fibo(int value)
{
    if (value == 0 || value == 1)
    {
        return value;
    }
    else 
    {
        return Fibo(value - 1) + Fibo(value - 2);
    }
}
