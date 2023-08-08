#define DEBUG	// 매크로 상수 정의

main() {
	int num = 3;
    #ifdef = DEBUG	// 만약 정의되어있으면 코드를 실행해라
    	printf("Currently num is %d.\n", num);
    #endif			// 여기까지
    ...
}