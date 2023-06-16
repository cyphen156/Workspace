#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void clac_BMI(float w, float h);

int main(void) {
    float weight, height;
    printf("Enter your weight.\n");
    scanf("%f", &weight);
    printf("Enter your height.\n");
    scanf("%f", &height);
    clac_BMI(weight, height);
    return 0;
}

void clac_BMI(float w, float h) {
    float result = w / (h * h);
    if (result < 18.5)
        printf("Your BMI is %.1f. It is Underweight.", result);
    else if (result < 25.0)
        printf("Your BMI is %.1f. It is normal.", result);
    else
        printf("Your BMI is %.1f. It is Overweight.", result);
}