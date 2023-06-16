#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

double clac_tax(int usage, int weather, double tax);

int main(void) {
    int usage, weather;
    double charge, tax = 13.7;
    printf("Enter monthly amount in Kwh.\n");
    scanf("%d", &usage);
    printf("Enter 1 if summer or winter, 0 if not.\n");
    scanf("%d", &weather);
    charge = clac_tax(usage, weather, tax);
    printf("Including tax, you pay %d.", (int)charge);
    return 0;
}

double clac_tax(int usage, int weather, double tax) {
    double result = 0;
    if (usage > 1000 && weather == 1) {
        result += 7300 + 709.5 * usage;
    }
    else if (usage > 400) {
        result += 7300 + 280.6 * usage;
    }
    else if (usage > 200) {
        result += 1600 + 187.9 * usage;
    }
    else {
        result += 910 + 93.3 * usage;
    }
    return result * (100 + tax) / 100;
}