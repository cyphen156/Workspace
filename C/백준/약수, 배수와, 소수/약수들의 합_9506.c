#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int n, sum;
    int arr[100000];

    scanf("%d", &n);
    while (n != -1) {
        sum = 0;
        int index = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                sum += i;
                arr[index++] = i;
            }
        }
        if (sum != n)
            printf("%d is NOT perfect.\n", n);
        else {
            printf("%d = ", n);
            for (int i = 0; i < index; i++) {
                printf("%d", arr[i]);
                if (i < index - 1)
                    printf(" + ");
            }
            printf("\n");
        }
        scanf("%d", &n);
    }
    return 0;
}
