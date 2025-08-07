/**
 * 백준 이항 계수 3_11401
 * 이항 계수는 두 개의 항을 전개 했을 때 나타나는 각 항의 계수를 말한다.
 * 자연수 N과 정수 K가 주어졌을 때, 
 * 이항 계수 (N, K)를 1,000,000,007로 나눈 나머지를 구하는 프로그램을 작성하시오.
 * *이전 문제의 아이디어를 그대로 차용할 수 있다.
 * ** 나눗셈에 대한 모듈러 연산은 적용할 수 없다
 * => 역원의 곱셈으로 계산해야 한다.
 * ==> 모듈러 p가 소수이다 
 * =:> 페르마의 소정리를 사용할 수 있다. 
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 4,000,001                    *
 * 0 <= K < N + 1                        *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 100분
 */


#include <iostream>
#define DIVISOR 1000000007
#define MAX_SIZE  4000001

using namespace std;

// static long long int memoizationFactorialArray[MAX_SIZE] = { 1 };

long long int result = 0;
const long long int divisor = DIVISOR;

long long int Factorial(long long int N);

long long int Inverse(long long int value);

long long int Power(long long int numerator
    , long long int denominator);

long long int SolveBinomialCoefficient(long long int n, long long int k);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long int N, K;
    cin >> N >> K;

    // long long int numerator = Factorial(N)  % divisor;                                 // N!
    // long long int denominator = Factorial(K) * Factorial(N - K)  % divisor;            // K!(N-K)!
    
    // // Inverse
    // // 나눗셈 a / b % p == a × b⁻¹ % p
    // denominator = Inverse(denominator);
    // result = numerator * denominator;
    // // result = DivideAndConquer(N, K);
    // cout << result % divisor << '\n';

    cout << SolveBinomialCoefficient(N, K) << '\n';

    return 0;
}

// long long int Factorial(long long int n)
// {
//     if (memoizationFactorialArray[n] != 0)
//     {
//         return memoizationFactorialArray[n];
//     }

//     memoizationFactorialArray[n] = (Factorial(n - 1) * n) % divisor;
    
//     return memoizationFactorialArray[n];
// }

long long int Inverse(long long int value)
{
    return Power(value, divisor - 2);
}

long long int Power(long long int base, long long int exponent)
{
    long long int result = 1;
    base %= divisor;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % divisor;
        }

        base = (base * base) % divisor;
        exponent >>= 1;
    }
    return result;
}

long long int SolveBinomialCoefficient(long long int n, long long int k)
{
    if (k > n)
    {
        return 0;
    } 

    if (k == 0 || k == n) 
    {
        return 1;
    }
    
    if (k > n - k) 
    {
        k = n - k;
    }

    long long int numerator = 1;
    long long int denominator = 1;

    for (long long int i = 1; i <= k; ++i)
    {
        numerator = (numerator * (n - i + 1)) % divisor;
        denominator = (denominator * i) % divisor;
    }

    // long long int inverseDenominator = Inverse(denominator);
    // return (numerator * inverseDenominator) % divisor;
    return numerator * Power(denominator, divisor - 2) % divisor;
}
