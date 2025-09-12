#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Point
{
    int x;
    int y;
}Point;

int cmp_x(const void* p, const void* q) 
{
    const Point *a = (const Point*)p, *b = (const Point*)q;
    if (a->x != b->x) 
    {
        return (a->x < b->x) ? -1 : 1;
    }

    return (a->y < b->y) ? -1 : 1;
}
int cmp_y(const void* p, const void* q) 
{
    const Point *a = (const Point*)p, *b = (const Point*)q;
    if (a->y != b->y) 
    {
        return (a->y < b->y) ? -1 : 1;
    }
    return (a->x < b->x) ? -1 : 1;
}

double Distance(Point a, Point b)
{
    return sqrt((double)(a.x - b.x) * (a.x - b.x) +
            (double)(a.y - b.y) * (a.y - b.y));
}

double Solve(Point* px, int l, int r)
{
    double best = 1e18;
    for (int i = l; i < r; i++)
    {
        for (int j = i + 1; j < r; j++)
        {
            double d = Distance(px[i], px[j]);
            if (d < best)
            {
                best = d;
            }
        }
    }
    return best;
}

double Stripe(Point* strip, int sz, double d)
{
    double best = d;

    qsort(strip, sz, sizeof(Point), cmp_y);

    for (int i = 0; i < sz; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            if (fabs((double)strip[j].y - (double)strip[i].y) >= best)
            {
                break;
            }

            double cur = Distance(strip[i], strip[j]);
            if (cur < best)
            {
                best = cur;
            }
        }
    }

    return best;
}

double Divide(Point* px, Point* tmp, int l, int r)
{
    int n = r - l;
    if (n <= 3)
    {
        return Solve(px, l, r);
    }

    int m = l + n / 2;
    int midx = px[m].x;

    double dL = Divide(px, tmp, l, m);
    double dR = Divide(px, tmp, m, r);
    double d = (dL < dR) ? dL : dR;

    int sz = 0;
    for (int i = l; i < r; i++)
    {
        if (fabs((double)px[i].x - (double)midx) < d)
        {
            tmp[sz++] = px[i];
        }
    }

    d = Stripe(tmp, sz, d);
    return d;
}

int main(void)
{
    int N;
    scanf("%d", &N);

    Point* points = malloc(N * sizeof(Point));
    Point* tmp    = malloc(N * sizeof(Point));

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    qsort(points, N, sizeof(Point), cmp_x);

    double best2 = Divide(points, tmp, 0, N);
    printf("%.6f\n", (best2));

    free(tmp);
    free(points);
    return 0;
}