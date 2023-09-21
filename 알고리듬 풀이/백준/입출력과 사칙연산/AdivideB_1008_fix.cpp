#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int main()
{
	double A, B;
	scanf("%lf%lf", &A, &B);
	printf("%.9lf", A / B);
	return 0;
}