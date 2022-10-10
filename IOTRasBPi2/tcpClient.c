#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 9000
#define IPADDR "127.0.0.1"

int main(void){
    int c_socket;
    struct sockaddr_in s_addr;
    char sndBuffer[BUFSIZ], rcvBuffer[BUFSIZ];
    int n;
    c_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    memset(&s_addr, 0, sizeof(s_addr));
    s_addr.sin_addr.s_addr = inet_addr(IPADDR);
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(PORT);
    if(connect(c_socket, (struct sockaddr*)&s_addr, sizeof(s_addr)) == -1){
        printf("Can not connect!!!\n");
        close(c_socket);
        return -1;
    }
    while(1){
        memset(sndBuffer, 0, BUFSIZ);
        printf("Input message to send to server.\n");
        printf("if you want to quit, type quit.\n");
        if((n = read(0, sndBuffer, BUFSIZ)) > 0){
            sndBuffer[n] = '\0';
        if(!strcmp(sndBuffer, "quit\n"))
            break;
        printf("original Data : %s", sndBuffer);
        if((n = write(c_socket, sndBuffer, strlen(sndBuffer))) < 0){
            return -1;
        }
        memset(rcvBuffer, 0, BUFSIZ);
        if((n = read(c_socket, rcvBuffer, BUFSIZ)) < 0){
            return -1;
        }

        printf("echoed Data : %s", rcvBuffer);
        }
    }
    close(c_socket);

    return 0;
}