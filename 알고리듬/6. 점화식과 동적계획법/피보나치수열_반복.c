// 피보나치 수열 점화식
// F(n) = F(n-1) + F(n-2), F(0) = 0, F(1) = 1
#include <time.h>
#include <stdio.h>

#define MAX_SIZE 15000000

static long long memoizationArray[MAX_SIZE];

void InitializeFibonacci_loop(long long n)
{
    for (long long i = 2; i <= n; ++i)
    {
        memoizationArray[i] = -1;
    }

    memoizationArray[0] = 0;
    memoizationArray[1] = 1;
}

long long Fibonacci_loop(long long n)
{
    long long value = 0;

    int i = 0;
    while (i != n)
    {
        memoizationArray[i+2] = memoizationArray[i+1] + memoizationArray[i];
        i++;
    }

    return memoizationArray[i];
}

int main(void)
{
    clock_t start, end;
    start = clock();

    long long n = MAX_SIZE;

    InitializeFibonacci_loop(n);
    long long result = Fibonacci_loop(n);
    
    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("fibonacci(%lld) result : %lld\n", n, result);
    printf("running Time : %.15lf sec\n", cpu_time_used);
    return 0;
}