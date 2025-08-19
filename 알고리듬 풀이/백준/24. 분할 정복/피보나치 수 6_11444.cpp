/**
 * 백준 피보나치 수 6_11444
 * 매우 거대한 피보나치 수를 빠르게 구하는 프로그램을 작성하라
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 1,000,000,000,000,000,001    *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 10 + 110분
 */


#include <iostream>

static const unsigned long long MAX_VALUE = 1000000000000000001ULL;
static const int MOD = 1000000007;
using namespace std;

static unsigned long long N;

pair<long long, long long> fibo(unsigned long long value);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    cout << fibo(N).first << '\n';
    return 0;
}

pair<long long, long long> fibo(unsigned long long n) 
{
    if (n == 0ULL) 
    {
        return {0LL, 1LL};
    }

    auto p = fibo(n >> 1);
    long long f_k  = p.first;                   // F(k)
    long long f_k1 = p.second;                  // F(k+1)

    long long two_fk1 = (2LL * f_k1) % MOD;
    long long t = (two_fk1 - f_k + MOD) % MOD;

    long long f2k = (f_k * t) % MOD;       
    long long f2k1 = ((f_k * f_k) % MOD + (f_k1 * f_k1) % MOD) % MOD;

    if ((n & 1ULL) == 0ULL) 
    {
        return {f2k,  f2k1};               // (F(2k),   F(2k+1))
    }
    else
    {
        return {f2k1, (f2k + f2k1) % MOD};  // (F(2k+1), F(2k+2))
    }
}