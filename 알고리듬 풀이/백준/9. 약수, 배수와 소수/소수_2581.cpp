/**
 * 백준 소수_2581
 * 자연수 M이상 N이하 수중 소수인 것을 모두 찾아 소수들의 합과 최솟값을 찾는 프로그램.
 * 이전 문제인 에라토스테네스의 체를 함수 형태로 기본 포함하고 시작한다.
 * 
 * 제한사항
 *****************************************
 * 0 < M <= N <= 10,0000                 *
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

#define SIZE 10001

using namespace std;

void isPrime(bool bCheckArray[])
{
    // 선제적 소수 판정
    for (int i = 2; i * i < SIZE; ++i)
    {
        if (!bCheckArray[i])
        {
            for (int j = i*i; j < SIZE; j += i)
            {
                bCheckArray[j] = true;
            }
        }
    }

}
int main(void)
{
    int M, N;
    cin >> M >> N;

    int sum = 0;
    int min = N;
    // true is not Prime
    // default == false means Prime
    bool checkPrimal[SIZE] = {false};

    checkPrimal[0] = checkPrimal[1] = true;

    int cnt = 0;

    isPrime(checkPrimal);
    
    for (int i = M; i < N+1; ++i)
    {
        if (!checkPrimal[i])
        {
            // 소수이고
            if (min > i)
            {
                // 현재 수보다 저장된 수가 크면 바꿔라
                min = i;
            }
            sum += i;
        }
    }
    if (sum == 0)
    {
        // 더해진 수가 없다는건 소수가 없다는 뜻
        cout << -1 << endl;
    }
    else 
    {
        cout << sum  << '\n' << min << endl;
    }
    return 0;
}