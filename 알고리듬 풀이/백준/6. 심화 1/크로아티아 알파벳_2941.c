/**
 * 백준 크로아티아 알파벳_2941
 * 
 * č	c=
 * ć	c-
 * dž	dz=
 * đ	d-
 * lj	lj
 * nj	nj
 * š	s=
 * ž	z=
 * 
 * 위의 문자들을 모두 하나의 문자로 생각하여 문자열에서 나타난 단어 개수를 세야 한다.
 * 
 * 제한사항
 ********************************************
 * 0 < strlen <= 100                        *
 * str elements always lower alpha or - or =*
 ********************************************
 *
 *
 *
 * 주의
 * 
 * 
 * 풀이시간 10분
 */


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int cnt = 0;
    char s[100] = { 0 };
    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '=' || s[i] == '-')
            continue;
        if (s[i] == 'l' || s[i] == 'n')
            if (s[i + 1] == 'j')
                continue;
        if (s[i] == 'd')
            if (s[i + 1] == 'z')
                if (s[i + 2] == '=')
                continue;        
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}