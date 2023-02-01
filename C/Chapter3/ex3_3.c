//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int one, two, three;

	//에러가 발생하는 코드영역 (Line 9~12)
	one = 1;
	three = two + 1;	//초기화되지 않은 변수 two를 사용하려 하기 때문에 에러가 발생한다.
	two = one + 1;
	printf("one: %d, two: %d, three: %d\n", one, two, three);

	//에러가 발생하지 않는 코드영역 (Line 15~18)
	one = 1;
	two = one + 1;
	three = two + 1;
	printf("one: %d, two: %d, three: %d\n", one, two, three);
	return 0;
}