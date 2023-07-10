/*
    런타임 에러 발생 코드 == > 사실 배열쓸 필요 없다 
    #define _CRT_SECURE_NO_WARNINGS

    #include <stdio.h>

    int main() {
        int a, b, cnt = 0, arr[100] = { 0 };

        scanf("%d %d", &a, &b);
        for (int i = 1; i <= a; i++) {
            if (a % i == 0) {
                arr[i] = 1;
                cnt++;
            }
            if (cnt == b && arr[i] == 1)
                printf("%d\n", i);
        }
        if (cnt < b)
            printf("0\n");
        return 0;
    }
*/

//수정된 코드
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int a, b, cnt = 0;

    scanf("%d %d", &a, &b);
    for (int i = 1; i <= a; i++) {
        if (a % i == 0) {
            cnt++;
        }
        if (cnt == b) {
            printf("%d\n", i);
            break;
        }
    }
    if (cnt < b)
        printf("0\n");
    return 0;
}
