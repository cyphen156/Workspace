#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int show_menu() {
	int choice;
	printf("Press 1 to continue. 2 to exit.\n");
	scanf("%d", &choice);
	getchar();
	return choice;
}

int main() {
	int selection;

	selection = show_menu();
	printf("%d.\n", selection);
	return 0;
}
