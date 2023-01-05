#include <stdio.h>

int main() {
	int i;
	for (i = 0; i <= 127; i++) {
		printf("%d\t", i); // 여기에 프린트 문으로 i 값을 찍고 탭을 삽입할 것

		printf("%c\n", i); // 여기에 해당 문자를 찍고 줄을 바꿀 것
	}
	return 0;
}