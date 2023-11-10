/**
* 백준 OX퀴즈 8958
* 
* cnt 변수를 통한 OX제어
* 
* 
* 제한사항
*****************************************
* 0 <= str <= 80						*
*****************************************
* 
* 
* 
* 주의
* 
* 풀이시간 10분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i) {
		char str[81];
		scanf("%s", str);

		int cnt = 0;
		int result = 0;

		int j = 0;
		while (str[j] != '\0') {
			if (str[j] == 'O') {
				++cnt;
			}
			else if (str[j] == 'X') {
				cnt = 0;
			}
			result += cnt;
			++j;
		}
		printf("%d\n", result);
	}
	return 0;
}