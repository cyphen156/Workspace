#include <stdio.h>


int main() {
	short width; int height; float area;
	double total; int length; short num1, num2, sum;
	width = (short)10;
	height = 5;
	area = 100.0f;

	total = area + width * height;
	printf("Total is %lf\n", total);
	length = 3.14;
	printf("Length is %d.\n", length);

	length = (int)3.14;
	printf("Length is % d.\n", length);
	num1 = (short)10; num2 = (short)20;
	printf("sizeof(num1 + num2) is %d\n", sizeof(num1 + num2));
	printf("sizeof(\'a\' - \'A\') is %d\n", sizeof('a' - 'A'));

	sum = num1 + num2;
	printf("sizeof sum is %d.\n", sizeof(sum));
	return 0;
}