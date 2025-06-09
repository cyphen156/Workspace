/**
* 백준 소수구하기 1929
* 
* M이상, N이하 소수구하기
*
* 제한사항
*****************************************
* 1 <= M <= N <= 1,000,000				*
*****************************************
*
*
*
* 주의
* 
* 소수 찾는 공식은 3가지
* 1. 모두 나눠보거나, 
* 2. 반까지 확인해보거나
* 3. 에라토스테네스의 체를 사용하여 이미 구한 약수들을 모두 제거
* 
* 풀이시간 40분
*/

// solution 1 전체 확인하기
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//
//int main()
//{
//	int A, B;
//	scanf("%d%d", &A, &B);
//
//    for (int i = A; i <= B; i++) {
//        int isPrime = 1;
//        // 1 처리
//        if (i == 1) isPrime = 0;
//        for (int j = 2; j < i; j++) {
//            // 소수가 아님
//            if (i % j == 0) {
//                isPrime = 0;
//                break;
//            }
//        }
//        if (isPrime) {
//            printf("%d\n", i);
//        }
//    }
//	return 0;
//}

//solution 2 반만 확인하기
// 

//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//int main()
//{
//	int A, B;
//	scanf("%d%d", &A, &B);
//
//    for (int i = A; i <= B; i++) {
//        int isPrime = 1;
//        // 1 처리
//        if (i == 1) isPrime = 0;
//        for (int j = 2; j <= i / 2; j++) {
//            if (i % j == 0) {
//                isPrime = 0;
//                break;
//            }
//        }
//        if (isPrime) {
//            printf("%d\n", i);
//        }
//    }
//	return 0;
//}

// solution 3 에라스토테네스의 체
// 배열을 통한 약수 저장

//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//
//int isPrime[1000001] = { 0 };
//
//int main() {
//	int A, B;
//	scanf("%d%d", &A, &B);
//	
//
//	// 배열 인덱스 0, 1 기본초기화
//	isPrime[0] = 1;
//	isPrime[1] = 1;
//	
//    //배열 수정
//    for (int i = 2; i * i <= B; i++) { // 제곱근까지만 확인
//        if (isPrime[i] == 0) {
//            for (int j = i * i; j <= B; j += i) {
//                isPrime[j] = 1;
//            }
//        }
//    }
//
//    // 출력
//    for (int i = A; i <= B; i++) {
//        if (isPrime[i] == 0) {
//            printf("%d\n", i);
//        }
//    }
//	return 0;
//}
