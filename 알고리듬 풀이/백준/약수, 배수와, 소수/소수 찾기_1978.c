#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int n, cnt = 0;
    int arr[1000] = { 0 };

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 1)
            continue;
        int j;
        for (j = 2; j < arr[i]; j++) {
            if (arr[i] % j == 0) {
                break;
            }
        }
        if (j == arr[i])
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}
