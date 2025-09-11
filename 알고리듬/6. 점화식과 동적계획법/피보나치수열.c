// 피보나치 수열 점화식
// F(n) = F(n-1) + F(n-2), F(0) = 0, F(1) = 1
#include <time.h>
#include <stdio.h>

int Fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return Fibonacci(n-1) + Fibonacci(n-2);
}

int main(void)
{
    clock_t start, end;
    start = clock();

    int n = 50;
    int result = Fibonacci(n);
    
    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("fibonacci(%d) result : %d\n", n, result);
    printf("running Time : %.15lf sec\n", cpu_time_used);
    return 0;
}