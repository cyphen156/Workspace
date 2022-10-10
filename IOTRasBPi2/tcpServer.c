#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9000

int main(void) {
    int s_socket, c_socket;
    struct sockaddr_in s_addr, c_addr;

    int n;
    int len;
    char rcvBuffer[BUFSIZ];

    s_socket = socket(AF_INET, SOCK_STREAM, IPPORTO_TCP);

    memset(&s_addr, 0, sizeof(s_addr));
    s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(PORT);
    if(bind(s_socket, (struct sockaddr*)&s_addr, sizeof(s_addr)) == -1){
        printf("Can not Bind!!!\n");
        return -1;
    }
    if(listen(s_socket, 5) == -1){
        printf("Listen Fail!!!\n");
        return -1;
    }
    while(1){
        printf("Echo Server started...\n");
        len = sizeof(c_addr);
        c_socket = accept(s_socket, (struct sockaddr*)&c_addr, &len);
        printf("Connected IP : %s\n", inet_ntoa(c_addr.sin_addr));
        while((n = read(c_socket, rcvBuffer, sizeof(rcvBuffer))) > 0){
            rcvBuffer[n] = '\0';
            printf("%s", rcvBuffer);
            write(c_socket, rcvBuffer, n);
        }
        printf("client bye~~\n");
        close(c_socket);
    }
    close(s_socket);
    return 0;
}