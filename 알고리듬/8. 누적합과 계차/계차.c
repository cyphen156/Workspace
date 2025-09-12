void build_diff(long long* A, int N, long long* D)
{
    D[1] = A[1];
    for (int i = 2; i <= N; i++)
    {
        D[i] = A[i] - A[i - 1];
    }
    D[N + 1] = 0; // 가드
}

void range_add(long long* D, int l, int r, long long v)
{
    D[l] += v;
    D[r + 1] -= v;
}

void restore_from_diff(long long* D, int N, long long* A)
{
    A[1] = D[1];
    for (int i = 2; i <= N; i++)
    {
        A[i] = A[i - 1] + D[i];
    }
}