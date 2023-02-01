//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int salary, bonus, total;

	salary = 400;
	bonus = 20;
	salary + bonus; //연산을 수행하였지만 아무것도 리턴받을 곳이 없기 때문에 결과는 메모리에서 지워진다.
	total = salary + bonus;
	printf("Total is, %d\n", total);

	bonus = salary = 400;   //400이라는 r-value를 salary에 대입한 후 salary를 다시 bonus에 대입한다.
	printf("Bonus plus salary is %d\n", bonus + salary);
	return 0;
}