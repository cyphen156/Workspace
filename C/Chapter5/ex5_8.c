#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int a = 1, b = 0;

	if (a)	// true becaues a == 1 means True
		if (b)	// false because b == 0 means false
			printf("a and b are both true.\n");
	else	// a조건문과 매칭되는 else인 것 같지만 b조건문과 매칭되는 else문이다
		//따라서 결과는 아무것도 출력되지 않는 게 아니라 elese의 출력문이 출력되고 프로그램이 종료된다.
		printf("a is not true");	
	return 0;
}
