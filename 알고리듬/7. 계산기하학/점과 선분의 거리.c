#include <stdio.h>
#include <math.h>

typedef struct Point
{
    int x;
    int y;
}Point;

typedef struct Vector
{
    int x; 
    int y;
}Vector;

Vector CreateVectorFromPoints(Point A, Point B) 
{
    Vector v;
    v.x = B.x - A.x;
    v.y = B.y - A.y;
    return v;
}

double Dot(Vector a, Vector b) 
{
    return a.x * b.x + a.y * b.y;
}

double Cross(Vector a, Vector b) 
{
    return a.x * b.y - a.y * b.x;
}

double Length(Vector v) {
    return sqrt((double)v.x * v.x + (double)v.y * v.y);
}

int main(void)
{
    Point A = {3, 5}, B = {5, 4}, C = {-3, 2};
    
    Vector CA = CreateVectorFromPoints(C, A);
    Vector CB = CreateVectorFromPoints(C, B);

    printf("CA = (%d, %d)\n", CA.x, CA.y);
    printf("CB = (%d, %d)\n", CB.x, CB.y);

    double square = fabs(Cross(CB, CA));

    double dist = square / Length(CB);
    printf("From CB To A = %.5f\n", dist);

    return 0;
}



