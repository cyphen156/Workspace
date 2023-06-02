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
	if (ch == 'A')
		printf("Exellent.\n");
	else if (ch == 'B')
		printf("Good.\n");
	else if (ch == 'C')
		printf("Not Bad.\n");
	else if (ch == 'D')
		printf("Need effort.\n");
	else if (ch == "F")
		printf("You can do better than this.\n");
	else
		printf("No such grade.\n");
}