#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//잔돈반환 프로그램 심화 -- 잔돈이 모자랄때 까지 반환하는 프로그램
int main() {
	int money, cost500, cost100, cost50, cost10;
	int cnt1 = 20, cnt2 = 20, cnt3 = 20, cnt4 = 20;
	printf("현재 남은 잔돈 개수\n500원 : %d개 100원 : %d개 50원 : %d개 10원 : %d개\n", cnt1, cnt2, cnt3, cnt4);
	printf("Enter the amount of change.\n");
	scanf("%d", &money);
	getchar();
	while (1) {
		if (cnt1 != 0) {
			cost500 = money / 500;
			money -= cost500 * 500;
			cnt1 -= cost500;
		}
		if (cnt2 != 0) {
			cost100 = money / 100;
			money -= cost100 * 100;
			cnt2 -= cost100;
		}
		if (cnt3 != 0) {
			cost50 = money / 50;
			money -= cost50 * 50;
			cnt3 -= cost50;
		}
		if (cnt4 != 0) {
			cost10 = money / 10;
			money -= cost10 * 10;
			cnt4 -= cost10;
		}
		printf("잔돈반환 500원: %d개, 100원: %d개, 50원: %d개, 10원: %d개\n", cost500, cost100, cost50, cost10);
		printf("현재 남은 잔돈 개수\n500원 : %d개 100원 : %d개 50원 : %d개 10원 : %d개\n", cnt1, cnt2, cnt3, cnt4);
		if (cnt1 <= 0 || cnt2 <= 0 || cnt3 <= 0 || cnt4 <= 0) {	// 잔돈체크
			printf("잔돈이 모자랍니다. 프로그램을 종료합니다.\n");
			break;
		}
		printf("Enter the Next amount of change.\n");
		scanf("%d", &money);
		getchar();
	}
	return 0;
}