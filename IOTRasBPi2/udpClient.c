#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9000

int main(void){
    int sd;
    struct sockaddr_in s_addr;
    int n, n_send;
    int addr_len;
    char sndBuffer[BUFSIZ];
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&s_addr, 0, sizeof(s_addr));
    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    s_addr.sin_port = htons(PORT)
    while(1) {
        printf("Input message to send to server.\n");
        printf("if you want to quit, type quit.\n");
        if((n = read(0, sndBuffer, BUFSIZ)) > 0) {
            sndBuffer[n] = '\0';
            if(!strcmp(sndBuffer, "quit\n")) break;
                printf("original Data : %s", sndBuffer);
            if ((n_send = sendto(sd, sndBuffer, strlen(sndBuffer), 0,
                (struct sockaddr *) &s_addr, sizeof(s_addr))) <0) {
                printf("sendto() error");
                return -1;
            }
            addr_len = sizeof(s_addr);
            if((n = recvfrom(sd, sndBuffer, sizeof(sndBuffer), 0,
                NULL, NULL)) < 0) {
                printf("recvfrom( ) error");
                return -1;
            }
            sndBuffer[n] = '\0';
            printf("echoed Data : %s", sndBuffer);
        }
    }
    close(sd);
}