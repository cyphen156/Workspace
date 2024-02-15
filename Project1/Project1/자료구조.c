///**
//* 스택자료구조 구현하기
//* //리스트
//* using struct
//* 
//*/
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct Node{
//	struct Node* next;
//	char* data;
//} Node;
//
////초기 공백노드 설정
//int stackSize = 0;
//Node* top = NULL;
//
//void menu(int n);
//int isEmpty();
//int push();
//void pop();
//void search();
//void printStack();
//void freeStack();
//
//int main() {
//
//	while (1)
//	{
//		int input;
//		printf("1 : stack push , 2 : stack pop, 3 : search data, 4 : print stack, 0 : 프로그램 종료\n");
//		scanf("%d", &input);
//		menu(input);
//	}
//	return 0;
//}
//
//// 명령어 입력기
//void menu(int n) {
//	if (n == 0)
//	{
//		freeStack();
//		printf("프로그램을 종료합니다.\n");
//		exit(0);
//	}
//	else if (n == 1)
//	{
//		push();
//	}
//	else if (n == 2)
//	{
//		pop();
//	}
//	else if (n == 3)
//	{
//		search();
//	}
//	else if (n == 4)
//	{
//		printStack();
//	}
//	else
//	{
//		printf("잘못된 입력입니다. 다시 입력해주세요.\n");
//	}
//}
//
//int isEmpty()
//{
//	//스택이 비었다면 true
//	if (stackSize == 0)
//	{
//		printf("스택이 비어있습니다.\n");
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int push()
//{
//	printf("저장할 단어를 입력해주세요. 단어의 길이는 최대 255입니다.\n");
//	char inputData[256] ;
//	scanf("%255s", inputData);
//	getchar();
//
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	if (newNode == NULL) {
//		printf("push실패!! 다시 시도해주세요.\n");
//		return -1;
//	}
//	newNode->data = _strdup(inputData);
//	newNode->next = top;
//	top = newNode;
//	++stackSize;
//	return 0;
//}
//
//void pop()
//{
//	if (isEmpty())
//	{
//		printf("단어를 저장해주세요.\n");
//		return;
//	}
//	Node* temp = top;
//	top = top->next;
//	printf("제거된 단어 : %s\n", temp->data);
//	free(temp->data);
//	free(temp);
//	stackSize--;
//}
//
//void search()
//{
//	if (isEmpty())
//	{
//		printf("단어를 저장해주세요.\n");
//		return;
//	}
//	printf("찾고  싶은 단어를 입력하세요.\n");
//	char inputData[256];
//	scanf("%255s", inputData);
//	getchar();
//
//	Node* temp = top;
//	int isFounded = 0;
//	for (int i = stackSize; i > 0; --i) 
//	{
//		if (strcmp(inputData, temp->data) == 0)
//		{
//			isFounded = 1;
//			printf("%s의 위치는 %d입니다.\n", inputData, i);
//			break;
//		}
//		temp = temp->next;
//	}
//	if (!isFounded)
//	{
//		printf("%s은/는 스택에 없습니다.\n", inputData);
//	}
//}
//
//void printStack()
//{
//	if (isEmpty())
//	{
//		printf("단어를 저장해주세요.\n");
//		return;
//	}
//	Node* temp = top;
//	for (int i = stackSize; i > 0; --i)
//	{
//		printf("스택의 위치 : %d, 저장된 단어 : %s\n", i, temp->data);
//		temp = temp->next;
//	}
//}
//
//void freeStack() {
//	while (top != NULL) {
//		pop();
//	}
//}