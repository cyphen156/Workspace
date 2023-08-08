#include <stdio.h>

/* 문자열 복사 */
void strcpy(char *dest, const char *src) {
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

/* 문자열의 지정된 길이만큼 복사 */
void strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
}
/* 문자열 연결 */
void strcat(char *dest, const char *src) {
    int dest_len = strlen(dest);
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
}

/* 문자열의 지정된 길이만큼 연결 */
void strncat(char *dest, const char *src, size_t n) {
    int dest_len = strlen(dest);
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
}

/* 문자열 비교 */
int strcmp(const char *str1, const char *str2);

/* 문자열의 지정된 길이만큼 비교 */
int strncmp(const char *str1, const char *str2, size_t n);

/* 지역화된 문자열 비교 */
int strcoll(const char *str1, const char *str2);

/* 문자열에서 문자 찾기 */
char *strchr(const char *str, int c);

/* 문자열에서 문자를 뒤에서부터 찾기 */
char *strrchr(const char *str, int c);

/* 문자열에서 문자 집합의 일치하는 부분 길이 계산 */
size_t strspn(const char *str, const char *set);

/* 문자열에서 문자 집합과 일치하지 않는 부분 길이 계산 */
size_t strcspn(const char *str, const char *set);

/* 문자열에서 어떤 문자 집합 중 하나라도 처음으로 일치하는 위치를 찾기 */
char *strpbrk(const char *str, const char *set);

/* 문자열에서 하위 문자열 찾기 */
char *strstr(const char *haystack, const char *needle);

/* 문자열 토큰화 */
char *strtok(char *str, const char *delim);

/* 문자열 변환 */
size_t strxfrm(char *dest, const char *src, size_t n);

/* 오류 번호에 해당하는 메시지 문자열 반환 */
char *strerror(int errnum);

/* 문자열의 길이 계산 */
size_t strlen(const char *str);

/* 메모리 복사 */
void *memcpy(void *dest, const void *src, size_t n);

/* 메모리 이동 */
void *memmove(void *dest, const void *src, size_t n);

/* 메모리 비교 */
int memcmp(const void *s1, const void *s2, size_t n);

/* 메모리에서 문자 찾기 */
void *memchr(const void *s, int c, size_t n);

/* 메모리 설정 */
void *memset(void *s, int c, size_t n);
