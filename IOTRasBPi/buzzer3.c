#include <wiringPi.h>
#include <softTone.h>
#include <stdio.h>
#define BuzPin  4


int notes[100];
int duration[100];
int scales[] = {523, 587, 659, 698, 784, 880, 987, 1046};
//do, re, mi, fa, sol, ra, si, do


int main(void) {
    char * filename;
    FILE * fp;
    char buf[80];
    int count = 0;
    filename = "music2.txt";

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("file open err");
        return 1;
    }
    while(!feof(fp)){
        fscanf(fp, "%d %d\n", &notes[count], &duration[count]);
        count++;
    }
    fclose(fp);
    int i;
    if(wiringPiSetupGpio() == -1)
        return -1;
    if(softToneCreate(BuzPin) == -1)
        return -1;

    while(1) {
        printf("Music is being played....\n");
        for (i = 0; i < count; i++) {
            softToneWrite(BuzPin, scales[notes[i]]);
            delay(duration[i]*500);
        }
    }   
    return 0;
}