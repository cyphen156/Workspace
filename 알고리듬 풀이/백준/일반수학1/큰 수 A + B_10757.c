/* 
    초기 코드는 C언어의 자료형 표현범위를 벗어나기때문에
    배열로 입력받아 이것을 연산한다는것을 찾음
    #define _CRT_SECURE_NO_WARNINGS

    #include <stdio.h>

    int main() {
        long long int A, B;
        
        scanf("%lld %lld", &A, &B);

        printf("%lld\n", A+B);
        return 0;
    }
    // 발생할 수 있는 문제 
    1. 두 문자열의 길이가 다른경우
        길이를 맞춰주던지 역순으로 더한다
    2. 덧셈 연산시 자릿수 올림이 발생할 경우
        부울린 형태의 변수를 제어하여 다음 연산에 사용

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    char A[10001], B[10001];
    int result[10001] = { 0 };
    int lenA = 0, lenB = 0, len, carry = 0;

    scanf("%s %s", A, B);
    // 각 문자열의 길이 체크
    for (int i = 0; A[i] != '\0'; i++) {
        lenA++;
    }
    for (int i = 0; B[i] != '\0'; i++) {
        lenB++;
    }
    // 두 문자열의 길이중 긴 문자열 길이 선택
    len = lenA > lenB ? lenA : lenB;
    
    for (int i = 0; i < len; i++) {
        int a = lenA - i - 1 >= 0 ? A[lenA - i - 1] - '0' : 0;
        int b = lenB - i - 1 >= 0 ? B[lenB - i - 1] - '0' : 0;
        result[i] = (a + b + carry) % 10;
        carry = (a + b + carry) / 10; // 올림 자릿수 연산
    }

    if (carry > 0)
        result[len++] = carry;

    for (int i = len - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    return 0;
}


/*
    참고한 코드 
    출처https://loding.tistory.com/entry/%EB%B0%B1%EC%A4%80C%EC%96%B8%EC%96%B4-10757%EB%B2%88-%ED%81%B0-%EC%88%98-AB
    #include <stdio.h>
    #include <string.h>
    
    int main(void){
        // long long int 최댓값: 2^63-1 = 9223372036854775807
        // A, B의 최댓값: 10^10000
        // 따라서 A, B를 문자열로 받고, 일의 자리부터 덧셈을 진행한다는 아이디어
    
        char A_str [10002]; //10^10000은 최대 10001자리, \0을 위한 1자리
        char B_str [10002];
        scanf("%s %s", A_str, B_str);
        int A_len = strlen(A_str);
        int B_len = strlen(B_str);
    
        int min_len, max_len;
        if(A_len < B_len){
            min_len = A_len;
            max_len = B_len;
        }
        else{
            min_len = B_len;
            max_len = A_len;
        }
        //printf("max_len: %d, min_len: %d\n", max_len, min_len);
    
        // A, B, sum 선언
        int A[10002];
        int B[10002];
        for(int count=0; count<10002; count++){
            A[count] = A_str[count]-'0';
            B[count] = B_str[count]-'0';
        }
    
        int sum [max_len];
        for(int num=0; num<max_len; num++){
            sum[num] = 0;
        }
    
        // 덧셈 진행
        for(int i=0; i<min_len; i++){
            int a = A[A_len-1-i];
            int b = B[B_len-1-i];
            //printf("a: %d, b: %d\n", a, b);
    
            int digit = (sum[i]+a+b)%10;
            int overflow=0;
            if(sum[i]+a+b>=10)
                overflow=1;
            
            sum[i] = digit;
            if(min_len==max_len && i==min_len-1){ // i+1이 존재하지 않을 수 있음
                sum[i] += overflow*10; // 이 경우에만 두 자릿수를 저장
            }
            else{
                sum[i+1] += overflow;
            }
            //printf("%d\n", sum[i]);
        }
    
        // max_len - min_len 부분 덧셈
        for(int j=min_len; j<max_len; j++){ //min_len == max_len일 경우 제외
            if(A_len < B_len){
                sum[j]+=B[max_len-1-j];
            }  
            else
                sum[j]+=A[max_len-1-j];
    
            if(sum[j]>=10 && j!=max_len-1){
                sum[j]=sum[j]%10;
                sum[j+1]+=1;
            }
        }
    
        // 'sum'을 역순으로 출력
        for(int k=0; k<max_len; k++){
            printf("%d", sum[max_len-1-k]);
        }
    }
*/
