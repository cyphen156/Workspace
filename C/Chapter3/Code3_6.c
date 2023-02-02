#include <stdio.h>

int main() {
	int a, b, c, d, e;
	a = b = c = d = e = 1;
	a = a-- - ++b * (c = d = 10) + (e *= 2);
	//	1 - 2 * (c = 10) + 2	r-value 사칙 연산
	//	a = 1 - 20 + 2 == -17	a에 r-value대입 연산
	//	a -= 1; = -18	후위감산 연산
	printf("After calculation, a becomes %d.\n", a);
	return 0;
}