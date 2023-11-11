/**
*
	백준 9012 괄호

	올바른 문자열은 반드시 '(', ')'가 세트로 존재해야 한다.
	 == VPS
	 세트가 아니면 '문자열'

	 제한사항
	 ****************************************
	 *표준 입출력 사용						*
	 * T개의 테스트 데이터					*
	 * 괄호 문자열 한줄로 제공				*
	 * 2 <= str <= 50						*
	 *										*
	 * output = "YES" / "NO"				*
	 ****************************************
	  
	 두번째 샘플에서 nono yes출력
	 (다음 나오는 )로 완성되야 올바른 문자열임

	 풀이시간 30분
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int T = 0, flag;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		char str[51];
		scanf("%s", str);

		int j = 0;
		flag = 0;
		while (str[j] != '\0') {
			if (str[j] == '(') {
				flag++;
			}
			if (str[j] == ')') {
				flag--;
				if (flag < 0) {
					break;
				}
			}
			++j;
 		}
		if (flag == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}