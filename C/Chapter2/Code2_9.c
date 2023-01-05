#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	char name[6], purpose[20], grade;
	printf("이름, 수강 목적, 희망 학점을 입력하시오.\n");
	scanf("%s %s %c", &name, &purpose, &grade);
	printf("이름 : %s.\n", name);
	printf("수강 목적 : %s.\n", purpose);
	printf("희망 학점 : %c.\n", grade);
	return 0;
}