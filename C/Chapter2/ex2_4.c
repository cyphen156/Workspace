#include <stdio.h>


int main() {
	float area; double total;
	area = 0.1234567;
	printf("Area is %f.\n", area);
	total = 0.1234567;
	printf("total is %lf.\n", total);
	total = 0.1234567F;
	printf("total is %lf.\n", total);
	return 0;
}