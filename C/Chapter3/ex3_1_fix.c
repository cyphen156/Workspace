#include <stdio.h>

int main() {
	int my_age, your_age;
    //L-Value	R-Value
	int her_age = 20;	//her_age라는 변수에 20이라는 값을 대입합니다.

	my_age = her_age + 1;	//my_age는 20이라는 값을 가지고 있었지만 scanf()함수에 의해 사용자의 입력을 받아 다른 정수값을 대입하게 됩니다.
	printf("My age is %d.\n", my_age);

	my_age = your_age + 1;	//초기화 되지 않은 변수를 사용하려 했기 때문에 에러가 발생합니다.
	printf("My age is %d.\n", my_age);
    
    your_age = '\0';	//your_age를 NULL값으로 초기화합니다. == 0 또는 '\0'
    my_age = your_age + 1;	//변수를 NULL값으로 초기화 했을 경우 default는 0이므로 my_age는 1이 됩니다. 
	printf("My age is %d.\n", my_age);	//하지만 0과 NULL은 다른것이니 주의해주세요
	return 0;
}