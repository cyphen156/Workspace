#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

char cmd[100] = "sudo raspistill -t 5000 -o image/pic.jpg";
int main (void) {
    if (wiringPiSetupGpio() == -1)
        return 1;

        int i;

        printf("치즈~~!!\n");
        delay(10);
        system(cmd);

        return 0;
}