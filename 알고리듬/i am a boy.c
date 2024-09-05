#include <stdio.h>
#include <string.h>

// 이진 문자열 변환을 위한 버퍼 크기 정의
#define BINARY_BUFFER_SIZE 800

// 문자를 이진 문자열로 변환하는 함수
void charToBinary(char ch, char *binaryBuffer, size_t bufferSize) {
    for (int i = 7; i >= 0; --i) {
        // 버퍼가 초과되지 않도록 주의
        if (bufferSize > 0) {
            *binaryBuffer++ = (ch & (1 << i)) ? '1' : '0';
            bufferSize--;
        }
    }
    *binaryBuffer = '\0';
}

int main(void) {
    char *inputString = "i am a boy";
    char binaryBuffer[BINARY_BUFFER_SIZE] = {0};
    char tempBuffer[9];  // 각 문자의 이진 문자열을 저장할 임시 버퍼
    size_t inputLength = strlen(inputString);
    
    // 모든 입력 문자열의 문자를 순회하면서 이진 문자열로 변환
    for (size_t i = 0; i < inputLength; ++i) {
        charToBinary(inputString[i], tempBuffer, sizeof(tempBuffer));
        // 변환된 이진 문자열을 최종 버퍼에 추가
        strncat(binaryBuffer, tempBuffer, BINARY_BUFFER_SIZE - strlen(binaryBuffer) - 1);
        // 각 문자의 이진 문자열 사이에 공백 추가
        strncat(binaryBuffer, " ", BINARY_BUFFER_SIZE - strlen(binaryBuffer) - 1);
    }
    
    // 결과 출력
    printf("%s\n", binaryBuffer);

    return 0;
}
