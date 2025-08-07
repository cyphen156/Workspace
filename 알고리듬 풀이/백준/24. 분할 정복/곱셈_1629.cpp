/**
 * 백준 곱셈_1629
 * 자연수 A를 B번 곱하는데 수가 매우 커지므로 C로 나눈 나머지를 구하라.
 * 
 * 제한사항
 *****************************************
 * 1 <= A, B, C < 2,147,483,647 + 1      *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 10분
 */


#include <iostream>

using namespace std;

long long int Pow(long long int operand, long long int coefficient, long long int divisor);

static long long int A, B, C;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A >> B >> C;
    long long int result;

    result = Pow(A, B, C);
    cout << result << '\n';

    return 0;
}

long long int Pow(long long int operand, long long int coefficient, long long int divisor)
{
    if (coefficient == 0)
    {
        return 1;
    }

    long long int half = Pow(operand, coefficient / 2, divisor);
    long long int result = (half * half) % divisor;

    if (coefficient % 2 == 1)
    {
        result = (result * operand) % divisor;
    }

    return result;
}