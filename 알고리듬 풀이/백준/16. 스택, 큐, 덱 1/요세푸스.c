/*
	백준 10773 요세푸스
	N명의 사람이 원형 큐를 만들고,
	양의 정수 K번째 사람을 제거함
	N명의 사람을 모두 제거
	원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다.
	예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>

	제한사항
	1 ≤ K ≤ N ≤ 1,000
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* front = NULL;
Node* end = NULL;

void push(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (front == NULL) {
		front = newNode;
		end = newNode;
	}
	else {
		end->next = newNode;
		end = newNode;
	}
	end->next = front;
}

int pop(int k) {
	Node* current = front;
	Node* prev = end;

	for (int i = 1; i < k; i++) {
		prev = current;
		current = current->next;
	}

	int data = current->data;
	front = current->next;
	prev->next = current->next;

	if (current == end) {
		end = prev;
	}

	free(current);
	return data+1;
}

int main() {
	int n = 0, k;
	scanf("%d%d", &n, &k);
	// 큐 생성
	for (int i = 0; i < n; i++) {
		push(i);
	}

	printf("<");
	for (int i = 0; i < n - 1; i++) {
		printf("%d, ", pop(k));
	}
	printf("%d>\n", pop(k));

	return 0;
}