//#include <stdio.h>

int main() {
	/*
	전처리기에서 기본 입출력 명령어가 담겨있는
	stdio.h를 컴파일 환경에 조성하지 않았기 때문에
	main 함수 내부에서 printf()함수를 사용할 수 없어
	링크 에러가 발생합니다.
	*/
	printf("Hello World!!");
	
	/*
	return 0 뒤의 세미콜론(;)을 입력하지 않아
	컴파일러가 명령어의 종료를 알 수 없기 때문에
	컴파일 에러가 발생합니다.
	*/
	return 0
}