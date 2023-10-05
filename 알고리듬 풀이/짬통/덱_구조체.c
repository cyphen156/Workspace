#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct deque {
	int value;
	struct deque* front;
	struct deque* rear;
} deque;

deque* frontIndex = NULL;
deque* rearIndex = NULL;
int dequesize = 0;

void push_front(int n) {
	if (dequesize == 10000)
		return;
	deque* newNode = (deque*)malloc(sizeof(deque));

	newNode->front = NULL;
	newNode->value = n;
	newNode->rear = frontIndex;
	if (frontIndex) {
		frontIndex->front = newNode;
	}
	else {
		rearIndex = newNode;
	}
	frontIndex = newNode;

	dequesize++;
}

void push_back(int n) {
	if (dequesize == 10000)
		return;
	deque* newNode = (deque*)malloc(sizeof(deque));

	newNode->front = rearIndex;
	newNode->value = n;
	newNode->rear = NULL;
	if (rearIndex) {
		rearIndex->rear = newNode;
	}
	else {
		frontIndex = newNode;
	}
	rearIndex = newNode;

	dequesize++;
}

int pop_front() {
	if (frontIndex == NULL)
		return -1;

	int result = frontIndex->value;
	deque* old = frontIndex;
	frontIndex = frontIndex->rear;
	if (frontIndex)
		frontIndex->front = NULL;
	else
		rearIndex = NULL;

	free(old);
	dequesize--;

	return result;
}

int pop_back() {
	if (rearIndex == NULL)
		return -1;

	int result = rearIndex->value;
	deque* old = rearIndex;
	rearIndex = rearIndex->front;
	if (rearIndex)
		rearIndex->rear = NULL;
	else
		frontIndex = NULL;

	free(old);
	dequesize--;

	return result;
}

int empty() {
	if (dequesize == 0)
		return 1;
	else
		return 0;
}

int size() {
	printf("%d\n", dequesize);
	return 1;
}

int front() {
	if (empty() == 1)
		return -1;
	else
		return frontIndex->value;
}

int back() {
	if (empty() == 1)
		return -1;
	else
		return rearIndex->value;
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