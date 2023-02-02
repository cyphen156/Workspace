#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int money, cost500, cost100, cost50, cost10;
	printf("Enter the amount of change.\n");
	scanf("%d", &money);
	getchar();
	cost500 = money / 500;
	cost100 = money % 500/ 100;
	cost50 = money % 500 % 100 / 50;
	cost10 = money % 500 % 100 % 50 / 10;
	printf("500원: %d개, 100원: %d개, 50원: %d개, 10원: %d개", cost500, cost100, cost50, cost10);
	return 0;
}