#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 9001
#define IPADDR "127.0.0.1"

char buffer[BUFSIZ];
int main(void){
    int c_socket;
    struct sockaddr_in s_addr;
    int n;
    char temp;
    c_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    memset(&s_addr, 0, sizeof(s_addr));
    s_addr.sin_addr.s_addr = inet_addr(IPADDR);
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(PORT);
    if(connect(c_socket, (struct sockaddr*)&s_addr, sizeof(s_addr)) == -1){
        printf("Cannot connect\n");
        perror("Error Message");
        return -1;
    }
    printf("Input command..\n");
    scanf("%s", buffer);
    buffer[strlen(buffer)] = '\0';
    if((n = write(c_socket, buffer, strlen(buffer))) < 0){
        printf("Write error\n");
        exit(-1);
    }
    printf("Received Data : \n");
    while((n = read(c_socket, &temp, 1)) > 0){
        printf("%c", temp);
        if(temp == ' ')
            printf("\n");
    }
    close(c_socket);
    return 0;
}