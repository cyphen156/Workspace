/*
	프린터의 Queue 구현하기

	FIFO인쇄

	문서의 중요도에 따른 정렬

	일단 넣고, 정렬
	or 정렬 해서 넣기

	1. n은 테스트 케이스의 수
	2. 2줄에 걸쳐서 각 테스트 케이스를 입력
	2-1. 테스트 케이스의 첫 줄은 문서 갯수, 몇 번째로 출력되었는지 궁금한 번호
	2-2. 각 문서의 중요도

	제한사항
	테스트 케이스 의 문서 수
	0 < N < 101

	궁금한 번호
	** 주의 인덱스 1부터 아님 0부터임
	0 <= M <= N

	중요도
	1 <= value <= 9


	// 정렬 방식을 다시 해야한다
	// 나는 입력과 동시에 정렬하고 있다
	-> 출력 방식을 맞추려면 모두 입력받고, 그 다음에 노드를 찾아서 맨 뒤로 노드를 미뤄야한다.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int qSize = 0;

typedef struct queue {
	int important;
	int idx;
	struct queue* next;
} queue;

// 기본 노드 = null;
queue* front = NULL;
queue* rear = NULL;

void push(int value, int index) {
	queue* newQueue = (queue*)malloc(sizeof(queue));
	newQueue->important = value;
	newQueue->idx = index;
	newQueue->next = NULL;
	
	//첫 노드 연결
	if (front == NULL && qSize == 0) {
		front = newQueue;
		rear = newQueue;
	}
	else {
		//node size만큼 순회하면서 탐색 저장하는 작업을 만드세요
		queue* current = front;
		queue* prevent = NULL;
		while (current != NULL && current->important >= value) {
			prevent = current;
			current = current->next;
		}

		if (prevent == NULL) {
			newQueue->next = front;
			front = newQueue;
		}
		else if (current == NULL) {
			prevent->next = newQueue;
			rear = newQueue;
		}
		else {
			prevent->next = newQueue;
			newQueue->next = current;
		}
	}
	qSize++;
}

int searchNode(int m) {
	int result = 1;
	queue* current = front;
	for (int i = 0; i < qSize; ++i) {
		if (current->next == NULL || current-> idx == m) {
			return result;
		}
		else {
			current = current->next;
			result++;
		}
	}
	return -1;
}

void pop() {
	if (front == NULL)
		return;

	queue* temp = front;
	front = front->next;
	if (front == NULL)
		rear = NULL;
	free(temp);
	qSize--;
}

int main() {
	int t;
	scanf("%d", &t);
	int* result = (int*)malloc(t * sizeof(int));
	for (int i = 0; i < t; ++i) {
		front = NULL;
		rear = NULL;

		int n, m;
		scanf("%d%d", &n, &m);
		getchar();
		for (int j = 0; j < n; ++j) {
			int value;
			scanf("%d", &value);
			push(value, j);
		}
		result[i] = searchNode(m);
		getchar();
	}

	for (int i = 0; i < t; ++i) {
		printf("%d\n", result[i]);
	}
	free(result);
	return 0;
}