#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9000

int main(void){
    int sd;
    struct sockaddr_in s_addr, c_addr;
    int n, n_recv;
    int addr_len;
    char buff[BUFSIZ];
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&s_addr, 0, sizeof(s_addr));
    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    s_addr.sin_port = htons(PORT);
    if(bind(sd, (struct sockaddr *) &s_addr, sizeof(s_addr)) == -1){
        printf("Can not Bind! \n");
        return -1;
    }
    while(1) {
        printf("UDP Echo server started...\n");
        addr_len = sizeof(c_addr);
        if((n_recv = recvfrom(sd, buff, sizeof(buff), 0,
            (struct sockaddr *)&c_addr, &addr_len)) < 0) {
            printf("recvfrom( ) error");
            return -1;
        }
        printf("Connected IP : %s\n", inet_ntoa(c_addr.sin_addr));
        printf("%s", buff);
        if((n = sendto(sd, buff, n_recv, 0,
            (struct sockaddr *) &c_addr, sizeof(c_addr))) < 0){
            printf("sendto( ) error");
            return -1;
        }
    }
    close(sd);
    return 0;
}