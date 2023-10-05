#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nptr = NULL;
int* frontIndex = NULL;
int* rearIndex = NULL;
int dequesize = 0;

void push_front(int n) {
	if (dequesize == 10000)
		return;
	int* deque = (int*)malloc(3 * sizeof(int));

	deque[0] = (int)nptr;
	deque[1] = n;
	deque[2] = (int)frontIndex;


	if (frontIndex)
		((int*)frontIndex)[0] = (int)deque;
	if (dequesize == 0)
		rearIndex = deque;
	frontIndex = deque;

	dequesize++;
}

void push_back(int n) {
	if (dequesize == 10000)
		return;
	int* deque = (int*)malloc(3 * sizeof(int));

	deque[0] = (int)rearIndex;
	deque[1] = n;
	deque[2] = (int)nptr;

	if (rearIndex)
		((int*)rearIndex)[2] = (int)deque;
	if (dequesize == 0)
		frontIndex = deque;
	rearIndex = deque;

	dequesize++;
}

int empty() {
	if (dequesize == 0)
		return 1;
	else
		return 0;
}

int pop_front() {
	if (empty() == 1)
		return -1;
	else {
		int result = frontIndex[1];
		int* old = frontIndex;
		frontIndex = (int*)frontIndex[2];
		dequesize--;
		if (dequesize == 0)
			rearIndex = NULL;
		free(old);
		return result;
	}
}

int pop_back() {
	if (empty() == 1)
		return -1;
	else {
		int result = rearIndex[1];
		int* old = rearIndex;
		rearIndex = (int*)rearIndex[2];
		dequesize--;
		if (dequesize == 0)
			frontIndex = NULL;
		free(old);
		return result;
	}
}

int size() {
	printf("%d\n", dequesize);
	return 1;
}

int front() {
	if (empty() == 1)
		return -1;
	else
		return frontIndex[1];
}

int back() {
	if (empty() == 1)
		return -1;
	else
		return rearIndex[1];
}
int main() {
	int idx = 0;
	scanf("%d", &idx);
	getchar();

	for (int i = 0; i < idx; i++) {
		char command[20];
		gets(command);
		if (strncmp(command, "push_front", 10) == 0) {
			push_front(atoi(command + 11));
		}
		else if (strncmp(command, "push_back ", 10) == 0) {
			push_back(atoi(command + 10));
		}
		else if (strcmp(command, "pop_front") == 0) {
			printf("%d\n", pop_front());
		}
		else if (strcmp(command, "pop_back") == 0) {
			printf("%d\n", pop_back());
		}
		else if (strcmp(command, "size") == 0) {
			size();
		}
		else if (strcmp(command, "empty") == 0) {
			printf("%d\n", empty());
		}
		else if (strcmp(command, "front") == 0) {
			printf("%d\n", front());
		}
		else if (strcmp(command, "back") == 0) {
			printf("%d\n", back());
		}
	}
	return 0;
}