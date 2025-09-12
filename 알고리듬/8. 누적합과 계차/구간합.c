#include "누적합.c"

long long SectorSum(long long* S, int start, int end)
{
    return S[end] - S[start - 1];
}

long long SectorSum_Naive(long long* A, int start, int end)
{
    long long result = 0;
    for (int i = start; i <= end; ++i)
    {
        result += A[i];
    }

    return result;
}