/**
* 스택자료구조 구현하기
* 
* using pointer, malloc
* not using struct
* 
*/

#include <stdio.h>
#include <stdlib.h>

//노드 1개 사이즈
#define arrSize 2;

void menu(int n);
void isEmpty();
int push();
int pop();
void search();
void printStack();

int main() {
	//초기 공백노드 설정
	int* head = NULL;
	int* end = head;

	while (1)
	{
		int input;
		printf("1 : stackpush , 2 : stack pop, 3 : search, 4 : print stack, 0 : 프로그램 종료\n");
		scnanf("%d", &input);
		menu(input);
	}

	return 0;
}

// 명령어 입력기
void menu(int n) {
	if (n == 0)
	{
		printf("프로그램을 종료합니다.\n");
		exit(0);
	}
	else if (n == 1)
	{
		push();
	}
	else if (n == 2)
	{
		pop();
	}
	else if (n == 3)
	{
		search();
	}
	else if (n == 4)
	{
		printStack();
	}
	else
	{
		printf("잘못된 입력입니다. 다시 입력해주세요.");
	}
}

void isEmpty()
{
	if ()
}
