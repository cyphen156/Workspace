// 명령어를 저장해놓고 이거 꺼내서 써라

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[10000];
//char command[10000][10];
int topIndex = -1;

void push(int n) {
	if (topIndex < 10000 - 1) {
		++topIndex;
		stack[topIndex] = n;
	}
}

int empty() {
	if (topIndex == -1)
		return 1;
	else
		return 0;
}

int pop() {
	if (empty() == 1)
		return -1;
	else
		return stack[topIndex--];
}

int size() {
	printf("%d\n", topIndex +1);
	return 1;
}

int top() {
	if (empty() == 1)
		return -1;
	else
		return stack[topIndex];
}

int main() {
	int idx = 0;
	scanf("%d", &idx);
	getchar();
	//int* arr = (int*)malloc(idx * sizeof(int));

	// 명령어 저장 배열
	/*for (int i = 0; i < idx; i++) {
		gets(command[i]);
	}

	for (int i = 0; i < idx; i++) {

		if (strncmp(command[i], "push", 4) == 0) {
			push(atoi(command[i] + 5));
		}
		else if (strcmp(command[i], "pop") == 0) {
			printf("%d\n", pop());
		}
		else if (strcmp(command[i], "size") == 0) {
			size();
		}
		else if (strcmp(command[i], "empty") == 0) {
			printf("%d\n", empty());
		}
		else if (strcmp(command[i], "top") == 0) {
			printf("%d\n", top());
		}
	}*/

	for (int i = 0; i < idx; i++) {
		char command[10];
		gets(command);
		if (strncmp(command, "push", 4) == 0) {
			push(atoi(command + 5));
		}
		else if (strcmp(command, "pop") == 0) {
			printf("%d\n", pop());
		}
		else if (strcmp(command, "size") == 0) {
			size();
		}
		else if (strcmp(command, "empty") == 0) {
			printf("%d\n", empty());
		}
		else if (strcmp(command, "top") == 0) {
			printf("%d\n", top());
		}
	}
	return 0;
}