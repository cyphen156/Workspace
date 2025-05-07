#define _CRT_SECURE_NO_WARNINGS
/*
    백준 7785 회사에 있는 사람
    자유 출퇴근 -> 현재 회사에 있는 사람체크
    
    사전순의 역순 출력 => 문자열 정렬
    같은이름 enter leave체크 가능
    
    초기코드 - 병합정렬 (fail)
    2번째 코드 - 퀵정렬 (timeover)
    3번째 코드 - 병합정렬 (success)

    !! 회사에 존재하는 사람이 Leave만 하는 경우는 없다 -> 없는 사람은 반드시 배열에 두번저장됨

    !!! 위의 로직으론 해결할 수 없음 -> Enter - leave  enter와 같은 경우또한 처리 필요
    -> 결국 입출력 로그 상태를 관리해야함


    ---- 다른사람의 문풀 확인 결과 -----
    Enter-leave의 키쌍은 단 한번만을 적용시킨경우가 대부분 
    -> 내가 생각한 경우의수가 틀리지 않았음
    --> 문제풀이 알고리즘 과정중 다른 문제가 있음을 의미함
*/
/*
    제한사항
    ***
    라이브러리는 stdio.h만 사용
    struct 구조 사용불가
    ***
    출입기록
    2 <= n <= 10^6
    
    enter || leave
    사람이름1 != 사람이름2
    0 < 사람이름 <= 5

    입력 예시
    4
    Baha enter
    Askar enter
    Baha leave
    Artem enter

    출력예시
    Askar
    Artem
*/
/*
    문제 풀이 시간 : 240분
*/

#include <stdio.h>

char s[1000000][6];  // 각 단어를 저장
char temp[1000000][6];

int strcmp(char* a, char* b);
void strcpy(char* dest, char* src);
//int partition(char arr[][6], int low, int high);
//void q_sort(char arr[][6], int low, int high);
void merge(char arr[][6], int left, int mid, int right);
void mergeSort(char arr[][6], int left, int right);

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %*s", s[i]);
    }

    //q_sort(s, 0, n - 1);
    mergeSort(s, 0, n - 1);

    for (int i = n - 1; i >= 0; i--) {
        if (i > 0 && strcmp(s[i], s[i - 1]) == 0) {
            i--;
            continue;
        }
        printf("%s\n", s[i]);
    }
    return 0;
}

// 문자열 비교 함수
int strcmp(char* a, char* b) {
    int i = 0;
    while (a[i] == b[i]) {
        if (a[i] == '\0') return 0;
        i++;
    }
    return  a[i] - b[i];
}

// 문자열 복사 함수
void strcpy(char* dest, char* src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') i++;
}

//void swap(char* a, char* b) {
//    char t[6];
//    strcpy(t, a);
//    strcpy(a, b);
//    strcpy(b, t);
//}
//
//int partition(char arr[][6], int low, int high) {
//    char* pivot = arr[high];
//    int i = (low - 1);
//
//    for (int j = low; j <= high - 1; j++) {
//        if (strcmp(arr[j], pivot) < 0) {
//            i++;
//            swap(arr[i], arr[j]);
//        }
//    }
//    swap(arr[i + 1], arr[high]);
//    return (i + 1);
//}
//
//void q_sort(char arr[][6], int low, int high) {
//    if (low < high) {
//        int pi = partition(arr, low, high);
//
//        q_sort(arr, low, pi - 1);
//        q_sort(arr, pi + 1, high);
//    }
//}

void merge(char arr[][6], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    // 작은 순서대로 배열에 삽입
    while (i <= mid && j <= right) {
        if (strcmp(arr[i], arr[j]) <= 0) {
            strcpy(temp[k], arr[i]);
            i++;
        }
        else {
            strcpy(temp[k], arr[j]);
            j++;
        }
        k++;
    }

    // 남은 데이터도 삽입
    if (i > mid) {
        for (int t = j; t <= right; t++) {
            strcpy(temp[k], arr[t]);
            k++;
        }
    }
    else {
        for (int t = i; t <= mid; t++) {
            strcpy(temp[k], arr[t]);
            k++;
        }
    }

    // 임시 배열을 실제 배열로 옮김
    for (int t = left; t <= right; t++) {
        strcpy(arr[t], temp[t]);
    }
}

void mergeSort(char arr[][6], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2; // 중간 위치를 계산
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}