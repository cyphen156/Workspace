#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

char cmd[100] = "sudo raspivid -t 10000 -o vod/vod.h264";
int main (void) {
    if (wiringPiSetupGpio() == -1)
        return 1;

        int i;

        printf("영상찍자~~!!\n");
        delay(10);
        system(cmd);

        return 0;
}