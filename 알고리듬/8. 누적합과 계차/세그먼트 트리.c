#include <stdio.h>
#include <stdlib.h>

void build(long long* tree, long long* A, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(tree, A, node * 2, start, mid);
        build(tree, A, node * 2 + 1, mid + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void push(long long* tree, long long* lazy, int node, int start, int end)
{
    if (lazy[node] != 0)
    {
        long long add = lazy[node];
        tree[node] += add * (end - start + 1);
        if (start != end)
        {
            lazy[node * 2]     += add;
            lazy[node * 2 + 1] += add;
        }
        lazy[node] = 0;
    }
}

void update_range_add(long long* tree, long long* lazy,
                      int node, int start, int end, int l, int r, long long val)
{
    push(tree, lazy, node, start, end);

    if (r < start || end < l)
    {
        return;
    }
    if (l <= start && end <= r)
    {
        lazy[node] += val;
        push(tree, lazy, node, start, end);
        return;
    }

    int mid = (start + end) / 2;
    update_range_add(tree, lazy, node * 2,     start, mid, l, r, val);
    update_range_add(tree, lazy, node * 2 + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query_range_sum(long long* tree, long long* lazy,
                          int node, int start, int end, int l, int r)
{
    push(tree, lazy, node, start, end);

    if (r < start || end < l)
    {
        return 0;
    }
    if (l <= start && end <= r)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;
    long long L = query_range_sum(tree, lazy, node * 2,     start, mid, l, r);
    long long R = query_range_sum(tree, lazy, node * 2 + 1, mid + 1, end, l, r);
    return L + R;
}