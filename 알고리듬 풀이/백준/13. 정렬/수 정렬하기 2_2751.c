#define _CRT_SECURE_NO_WARNINGS
/*
    백준 2751 수 정렬하기
    내가 가장 좋아하는 정렬법은 버블소트 왜? 쉬우니까
    근데 문제풀이과정중 C6262 경고 발생
    -> 배열크기가 정수형 100만개 -> 너무크다
    동적할당 없이 할수있는게 뭐가있을까...?
    수의 중복이 없다고 했다 -> 이차원 배열로 해결해볼까?
    1000 X 1000크기의 이차원 연결배열
    XXXXX 해결되지 않는다 
    Why? 배열을 쪼개놧다고 해도 여전히 같은 크기의 배열을 생성하고 있기 때문
    -> 우선 작은 크기의 배열을 생성한 뒤 재생성 하던지, 
    퀵 소팅, 힙 소팅과 같은 추가 메모리가 필요하지 않은 소팅 필요
    -> 입력받음과 동시에 정렬 진행
    -> 계수 정렬 사용
    
    다시 생각하니 소팅법만 문제가 아니다
    얼마전 생각했던 const, define의 메모리 생성영역에 관한 이야기...
    전역변수로 선언해버리면
    메모리 사용 공간이 스택에서 힙으로 내려감
*/
/*
    제한사항
    line 1 : N
    line 2 : x1 x2 x3 ...xn

    0 < N <= 1,000,000
    0 <= | K | <= 1,000,000
    K1 != Kn
    */
/*
    문제 풀이 시간 : 30분
*/
//#include <stdio.h>
//int arr[1000000] = { 1000001 };
//
//int main() {
//    int N;
//    scanf("%d", &N);
//    for (int i = 0; i < N; i++) {
//        scanf("%d", &arr[i]);
//    }
//    for (int i = 0; i < N-1; i++) {
//        for (int j = i + 1; j < N; j++) {
//            if (arr[i] > arr[j]) {
//                int temp = arr[j];
//                arr[j] = arr[i];
//                arr[i] = temp;
//            }
//        }
//    }
//    for (int i = 0; i < N; i++) {
//        printf("%d\n", arr[i]);
//    }
//    return 0;
//}

#include <stdio.h>

char check[2000001] = { 0 };  //전역변수로 선언하여 메모리 할당 문제 해결

int main() {
    int N, num;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        // 입력이 절댓값이므로 음수 처리필요
        check[num + 1000000] = 1;
    }

    for (int i = 0; i < 2000001; i++) {
        if (check[i])
            printf("%d\n", i - 1000000);
    }

    return 0;
}
