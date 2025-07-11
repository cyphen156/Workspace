/**
 * 백준 약수_1037
 * 1과 N을 제외한 N의 약수를 모두 줄 때 원래 수 N을 구하시오
 * 
 * 제한사항
 *****************************************
 * InputCount is Divisor Count - 2       *
 * 0 < InputCount <= 50                  *
 * 2 <= Input <= 1,000,000               *
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

#define MAX_VALUE   1000001
#define MIN_VALUE   1

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int inputCount;
    int N;

    cin >> inputCount;

    int divisors[2];

    divisors[0] = MAX_VALUE;
    divisors[1] = MIN_VALUE;

    for (int i = 0; i < inputCount; ++i)
    {
        int input;
        cin >> input;
        
        if (divisors[0] > input)
        {
            divisors[0] = input;
        }

        if (divisors[1] < input)
        {
            divisors[1] = input;
        }
    }

    N = divisors[0] * divisors[1];
    cout << N << '\n';
    return 0;
}