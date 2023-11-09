/**
* 백준 균형잡힌세상 4949
* 
* 문자열문제 괄호의 확장,
* 소괄호 : () 대괄호 []
* 
* 
* 제한사항
*****************************************
* 문자열의 입력 종료 시퀀스는 ~~'.'		*
* 0 < str <= 100						*
* 프로그램 종료 시퀀스는 '.'				*
*****************************************
* 
* 유사 스택 사용
* 
* 주의
* Help( I[m being held prisoner in a fortune cookie factory)].
* ()()[][]만 정상괄호 (보다 [의 길이가 길어서는 안됨
* 풀이시간 10분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct Stack {
	char ch[100];
	int top;
	int squareBrackets;
	int parentheses;
}Stack;

void push(Stack* stack, char str) {
	if (str == '(') {
		stack->parentheses++;
	}
	else if (str == '[') {
		stack->squareBrackets++;
	}
	stack->ch[stack->top] = str;
	stack->top++;
}

int pop(Stack* stack, char str) {
	if (str == ')') {
		// 비정상 소괄호 입력
		if (stack->parentheses <= 0 
			|| stack->ch[stack->top - 1] == '[') {
			return -1;
		}
		stack->parentheses--;
	}
	else if (str == ']') {
		//비정상 대괄호 입력
		if (stack->squareBrackets <= 0 
			|| stack->ch[stack->top - 1] == '(') {
			return -1;
		}
		stack->squareBrackets--;
	}
	stack->top--;
	return 0;
}

int main() {
	// 입력 길이 제한
	char str[101];
	Stack stack;

	while (1) {
		//스택 초기화
		stack.parentheses = 0;
		stack.squareBrackets = 0;
		stack.top = 0;
		int i = 0;
		int err = 0;
		for (; i < 100; ++i) {
			str[i] = getchar();
			
			if (str[i] == '.')
				break;
			if (str[i] == '(' || str[i] == '[') {
				push(&stack, str[i]);
			}
			else if (str[i] == ')' || str[i] == ']') {
				if (pop(&stack, str[i]) == -1) {
					err = 1;
				}
			}
		}
		getchar();
		if (i == 0)
			break;
		// 문자열 종료처리
		str[i + 1] = '\0';

		if (stack.top == 0 && stack.parentheses == 0 && stack.squareBrackets == 0 && err == 0) {
			printf("yes\n");
		}
		else
			printf("no\n");
	}
	return 0;
}