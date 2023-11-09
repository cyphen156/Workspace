/**
* 백준 직각삼각형 4153
* 
* 삼각형의 세 변을 통해 직각인지 아닌지 판단하기
* 
* // 숨겨진 조건
* // 변의 길이가 하나라도 0이면 그건 삼각형이 아니다.
* => 0, 0, 0입력조건 이 아니라 0이 하나라도 입력되면으로 조건변경
* 
* 제한사항
*****************************************
* 무한반복 케이스						*
* 0, 0, 0 입력시 return-1				*
* 0 <= input <= 30,000					*
*****************************************
* 
* 풀이시간 10분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	while (1) {
		int arr[3] = { 0 }, temp;
		// 입력받기
		for (int i = 0; i < 3; ++i) {
			scanf("%d", &arr[i]);
		}
		// 삼각형이 아닌 것 처리, 종료 시퀀스 처리
		if (arr[0] == 0 || arr[1] == 0 || arr[2] == 0) {
			break;
		}

		// 정렬
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2 - i; j++) {
				if (arr[j] > arr[j + 1]) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}

		// 직각처리
		if ((arr[0] * arr[0]) + (arr[1] * arr[1]) == (arr[2] * arr[2])) {
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
	}
	return 0;
}