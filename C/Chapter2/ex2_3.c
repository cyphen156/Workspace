#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	printf("sizeof(char) is %d\n", sizeof(char));
	printf("sizeof(short) is %d\n", sizeof(short));
	printf("sizeof(int) is %d\n", sizeof(int));
	printf("sizeof(long) is %d\n", sizeof(long));
	printf("sizeof(long long) is %d\n", sizeof(long long));
	printf("sizeof(float) is %d\n", sizeof(float));
	printf("sizeof(double) is %d\n", sizeof(double));
	printf("sizeof(long double) is %d\n", sizeof(long double));
	printf("int ranges from %d to %d\n", INT_MIN, INT_MAX);
	printf("double ranges from %e to %e\n", DBL_MIN, DBL_MAX);
	return 0;
}