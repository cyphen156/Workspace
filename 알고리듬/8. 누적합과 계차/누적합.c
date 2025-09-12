long long prefix_sum(long long* A, int size, long long* S)
{
    S[0] = 0;
    for (int i = 1; i <= size; i++)
    {
        S[i] = S[i - 1] + A[i];
    }
    return 0;
}