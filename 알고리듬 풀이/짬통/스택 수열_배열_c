/* 
	스택으로 만드는 수열
	push와 pop을 구현하기
	순서는 오름차순으로 
	같은 정수의 입력은 없다

	제한사항 
	0 < N < 100,001
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[100001] = { 0 };
char printstack[100001];
int prtsize = 0;

void push(int i){
	printstack[i] = '+';
}

void pop(int i){
	printstack[i] = '-';
}

void print(int ptrsize) {
	for (int i = 0; i < ptrsize; i++) {
		printf("%c\n", printstack[i]);
	}
}

int main() {
	int N, max = 0, top = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int k;
		scanf("%d", &k);
		
		// 이미 등장한 수를 다시 push할 수 없음
		if (stack[k] == -1 || k > N) {
			printf("NO\n");
			return 0;
		}
		//입력받은 수가 여태 등장하지 않은 수면 거기까지 push하는 로직
		if (k > max) {
			for (int j = max + 1; j <= k; j++) {
				push(++prtsize);
			}
			max = k;
			top = k;
		}
		for (int j = top-k; j >= 0; j--) {
			stack[top] = -1;
			top--;
			pop(++prtsize);
		}
	}

	print(prtsize);
	return 0;
}

/*
#include <stdio.h>

int main() {
    int N, top = 0, max = 0, k;
    int stack[100001];
    char result[200002];  // push와 pop 각각에 대해 결과를 저장할 수 있게
    int idx = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &k);
        if (k > max) {
            for (int j = max + 1; j <= k; j++) {
                stack[top++] = j;
                result[idx++] = '+';
            }
            max = k;
        }
        
        if (stack[top-1] == k) { // 스택의 맨 위가 숫자와 일치하는지 확인
            top--;
            result[idx++] = '-';
        } else {
            printf("NO\n");
            return 0;
        }
    }

    for (int i = 0; i < idx; i++) {
        printf("%c\n", result[i]);
    }
    return 0;
}
*/