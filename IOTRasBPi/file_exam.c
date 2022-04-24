//파일 읽기
#include <stdio.h>

int main(void) {
    FILE * fp;
    char buf[80];

    fp = fopen("music.txt", "r");
    if (fp == NULL) {
        perror("File Open Error..");
        return(1);
    }
    while(fgets(buf, 80, fp) != NULL) {
        printf("%s", buf);
    }
    fclose(fp);

    return 0;
}