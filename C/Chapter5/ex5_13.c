#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void comment(char);

int main(void) {
	char grade;
	printf("Enter your grade in capital letter. __\b\b");
	scanf("%c", &grade);
	comment(grade);
	return 0;
}

void comment(char ch) {
	switch (ch) {
	case 'A':
		printf("Exellent.\n");
		break;
	case 'B':
		printf("Good.\n");
		break;
	case 'C':
		printf("Not Bad.\n");
		break;
	case 'D':
		printf("Need effort.\n");
		break;
	case 'F':
		printf("You can do better than this.\n");
		break;
	default:
		printf("No such grade.\n");
		break;
	}
	return;
}