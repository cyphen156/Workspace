#include <stdio.h>

int main() {
	int a, b;
	
    //1번 
	a = 0;
	a++;
	printf("after a++ = %d\n", a);
	b = a++;
	printf("after b = a++ == %d and a = %d\n\n", b, a);

	//2번
	a = 0;
	++a;
	printf("after ++a = %d\n", a);
	b = ++a;
	printf("after b = ++a == %d and a = %d\n\n", b, a);

	//3번
	a = b = 0;
	printf("a = %d, b = %d\n", a, b);
	printf("(1+a++) = %d, ++b = %d\n", (1+a++) + 2, ++b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}