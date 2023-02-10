#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char to_upper_case(char ch) {
	return ch - 32;
}

int main() {
	char ch;

	printf("알파벳 소문자를 입력하세요.\n");
	scanf("%c", &ch);
	getchar();

	printf("소문자 %c의 대문자는 %c입니다.\n", ch, to_upper_case(ch));
	return 0;
}
