#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int N;

    printf("Enter the maximum length N.\n");
    scanf("%d", &N);

    printf("The right-angled triangles are,\n");
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (i * i + j * j == k * k)
                    printf("%d %d %d\n", i, j, k);
            }
        }
    }
    return 0;
}
