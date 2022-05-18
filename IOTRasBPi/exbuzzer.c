#include <wiringPi.h>
#include <softTone.h>
#include <stdio.h>
#define BuzPin  4


int notes[200];
int duration[200];
float scales[] = {
0, 261.625, 293.665, 329.63, 349.23, 392, 440, 493.8, 
523.25, 587.33, 659.26, 698.46, 784, 880, 987.6, 
1046.5, 1174.66, 1318.52, 1396.92, 1568, 1760, 1975.2, 2093};
//do, re, mi, fa, sol, ra, si, do


int main(void) {
    char * filename;
    FILE * fp;
    char buf[160];
    int count = 0;
    filename = "exmusic.txt";

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
            delay(duration[i]*250);
        }
    }   
    return 0;
}
