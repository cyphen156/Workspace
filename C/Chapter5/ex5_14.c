#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void comment(char);

int main(void) {
	char grade;
	printf("Enter your grade.\n");
	scanf("%c", &grade);
	comment(grade);	
	return 0;
}

void comment(char ch) {
	switch (ch) {
	case 'A':
		printf("Exellent.\n");
	case 'B':
		printf("Good.\n");
		break;
	case 'c':
	case 'C':
		printf("Not Bad.\n");
		break;
	}
	return;
}