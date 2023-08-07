#define _CRT_SECURE_NO_WARNINGS

// 시저 사이퍼
// 고대 로마 제국 율리우스 카이사르 시대에 사용하던 암호화 기법
// 초기 암호화, 문자를 대체
#include <stdio.h>

int main(void) {
    int key;
    char ch;

    printf("Enter the key.\n");
    scanf("%d", &key);
    printf("Enter the text.\n");
    getchar();	//key값 입력시 같이 버퍼에 입력된 '\n'(Enter)제거

    while (1) {
        scanf("%c", &ch);
        if (ch == '\n')
            break;
        printf("%c", ch + key);
    }
    return 0;
}