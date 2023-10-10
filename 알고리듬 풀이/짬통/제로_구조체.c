/*
	백준 10773 제로
	동아리 회식 장부 관리
	잘못된 수를 부를 때 마다 0을 외쳐 최근의 수를 지움 
	==> pop()
	모든 수를 받아 적은 후 합을 알고싶음

	제한사항
	1 ≤ K ≤ 100,000
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* current = NULL;


void push(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = current;
	current = newNode;
}

int pop() {
	if (current == NULL) {
		return -1;
	}
	int data = current->data;
	Node* temp = current;
	current = current->next;
	free(temp);
	return data;
}

int main() {
	int n = 0, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);

		if (num == 0) {
			pop();
		}
		else {
			push(num);
		}
	}

	while (current != NULL) {
		sum += pop();
	}

	printf("%d\n", sum);
	return 0;
}