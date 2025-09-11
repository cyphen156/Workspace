// 피보나치 수열 점화식
// F(n) = F(n-1) + F(n-2), F(0) = 0, F(1) = 1
#include <time.h>
#include <stdio.h>

#define MAX_SIZE 15000

static long long memoizationArray[MAX_SIZE];

void InitializeFibonacci_DP(long long n)
{
    for (long long i = 2; i <= n; ++i)
    {
        memoizationArray[i] = -1;
    }

    memoizationArray[0] = 0;
    memoizationArray[1] = 1;
}

long long Fibonacci_DP(long long n)
{
    if (memoizationArray[n] != -1)
    {
        return memoizationArray[n];
    }

    long long value = Fibonacci_DP(n - 1) + Fibonacci_DP(n - 2);
    memoizationArray[n] = value;
    return value;
}

int main(void)
{
    clock_t start, end;
    start = clock();

    long long n = MAX_SIZE;

    InitializeFibonacci_DP(n);
    long long result = Fibonacci_DP(n);
    
    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("fibonacci(%lld) result : %lld\n", n, result);
    printf("running Time : %.15lf sec\n", cpu_time_used);
    return 0;
}