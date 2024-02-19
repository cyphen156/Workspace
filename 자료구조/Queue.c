/**
* 큐 자료구조 구현하기
* // 단일연결리스트
* using struct
*
* 걸린시간 100분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
	struct Node* next;
	char* data;
} Node;

typedef struct Queue {
	Node* front;	//헤드
	Node* rear;		//테일
} Queue;

void menu(int n);
bool isEmpty();
int enQueue();
int deQueue();
int search();
void printQueue();
void freeQueue();

Queue queue;

int main() {	
	queue.front = NULL;
	queue.rear = NULL;
	while (1)
	{
		int input;
		printf("1 : enQueue, 2 : deQueue, 3 : search data, 4 : print Queue, 0 : 프로그램 종료\n");
		scanf("%d", &input);
		menu(input);
	}

	return 0;
}

// 명령어 입력기
void menu(int n) {
	getchar();
	if (n == 0)
	{
		freeQueue();
		printf("프로그램을 종료합니다.\n");
		exit(0);
	}
	else if (n == 1)
	{
		enQueue();
	}
	else if (n == 2)
	{
		deQueue();
	}
	else if (n == 3)
	{
		search();
	}
	else if (n == 4)
	{
		printQueue();
	}
	else
	{
		printf("잘못된 입력입니다. 다시 입력해주세요.\n");
	}
}

bool isEmpty()
{
	if(queue.front == NULL)
	{
		printf("스택이 비어있습니다.\n");
		return true;	// return 1;
	}
	return false;		// return 0
}

int enQueue()
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	char src[256];
	printf("저장할 단어를 입력해주세요. 단어의 길이는 최대 255입니다.\n");
	fgets(src, 256, stdin);
	src[strcspn(src, "\n")] = 0;
	newNode->data = _strdup(src);
	newNode->next = NULL;

	if (queue.front == NULL)
	{
		printf("첫번째 데이터를 입력합니다.\n");
		queue.front = queue.rear = newNode;
	}
	else
	{
		queue.rear->next = newNode;
		queue.rear = newNode;
	}
	return 0;
}

int deQueue()
{
	if (isEmpty())
	{
		printf("단어를 저장해주세요.\n");
		return 0;
	}
	Node* temp = queue.front;		//첫번째 노드 뽑아내기
	queue.front = queue.front->next; // 다음 노드 가져오기
	if (queue.front == NULL) // 큐가 모두 비워졌음을 의미한다.
	{
		queue.rear == NULL; 
	}
	printf("제거된 단어 : %s\n", temp->data);
	free(temp->data);
	free(temp);
	return 1;
}

int search()
{
	if (isEmpty())
	{
		printf("단어를 저장해주세요.\n");
		return;
	}
	char src[256];
	printf("찾고싶은 단어를 입력해주세요. 단어의 길이는 최대 255입니다.\n");
	fgets(src, 256, stdin);
	src[strcspn(src, "\n")] = 0;
	Node* temp = queue.front;
	int i = 0;
	while (temp != NULL)
	{
		++i;
		if (strcmp(src, temp->data) == 0)
		{
			printf("%s의 위치는 %d입니다.\n", src, i);
			return 1;
		}
		temp = temp->next;
	}
	printf("찾으시는 단어는 스택에 없습니다.\n");
	return 1;
}

void printQueue()
{
	if (isEmpty())
	{
		printf("단어를 저장해주세요.\n");
		return;
	}
	Node* temp = queue.front;
	int i = 0;
	while (temp != NULL)
	{
		++i;
		printf("큐의 위치 : %d, 저장된 단어 : %s\n", i, temp->data);
		temp = temp->next;
	}
}

void freeQueue()
{
	while (!isEmpty())
	{
		deQueue();
	}
}
