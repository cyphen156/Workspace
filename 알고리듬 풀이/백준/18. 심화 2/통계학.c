/*
	백준 2108 통계학
	통계학의 기본 연산 4가지 구현하기
	산술평균 : N개의 수들의 합을 N으로 나눈 값
	중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
	최빈값 : N개의 수들 중 가장 많이 나타나는 값
	범위 : N개의 수들 중 최댓값과 최솟값의 차이

	제한사항
	1 ≤ N ≤ 500,000
	N % 2 == 1;
	-4000 <= K <= 4000
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500001
#define OFFSET 4000

int freq[8001] = { 0 };
// 개수, 중앙값, 범위,		최빈값		
// 최솟값			최댓값	
int N, mid = 0, range = 0, maxFreq = 0,
min = 0x7FFFFFFF, max = 0x80000000;
// 산술평균
double eval = 0.f;

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* front = NULL;

void push(int k) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = k;
	newNode->next = NULL;

	eval += k;

	if (k < min) min = k;
	if (k > max) max = k;

	if (!front) {
		front = newNode;
	}
	else if (front->data >= k) {
		newNode->next = front;
		front = newNode;
	}
	else {
		Node* current = front;
		while (current->next && current->next->data < k) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}

	freq[k + OFFSET]++;
	if (freq[k + OFFSET] > maxFreq) {
		maxFreq = freq[k + OFFSET];
	}
}

int main() {
	
	scanf("%d", &N);
	if (N % 2 == 0)
		return -1;
	
	for (int i = 0; i < N; ++i) {
		int K;
		scanf("%d", &K);
		push(K);
	}

	// 산술평균
	printf("%.0f\n", eval / N);

	// 중앙값 -> 입력받을때 이미 노드를 밀면서 오름차순 정렬하고있음
	Node* current = front;
	for (int i = 0; i < N / 2; i++) {
		current = current->next;
	}
	printf("%d\n", current->data);

	int modeValue = -1; // 최빈값
	int modeCount = 0; // 동일한 최빈값의 수

	for (int i = 0; i <= 8000; i++) {
		if (freq[i] == maxFreq) {
			if (modeCount == 1) {
				modeValue = i - OFFSET; // 두 번째 최빈값 저장
				break;
			}
			if (modeValue == -1) { // 첫 번째 최빈값 저장
				modeValue = i - OFFSET;
			}
			modeCount++;
		}
	}
	printf("%d\n", modeValue);

	// 범위
	range = max - min;

	printf("%d\n", range); 

	// 메모리 해제
	while (front) {
		Node* temp = front;
		front = front->next;
		free(temp);
	}
	return 0;
}