#include <stdio.h>

int main() {
	char grade; int sum;

	grade = 'A';
	sum = 0x40302010;
	printf("Grade starts at adderss %p.\n", &grade);
	printf("sum starts at adderss %p.\n", &sum);
	return 0;
}