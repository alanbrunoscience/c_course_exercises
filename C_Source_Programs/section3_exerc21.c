#include <stdio.h>

int main(){

    float lbs, kg;

    printf("Enter the mass in pounds (lbs), please:\n");
    scanf("%f", &lbs);

    kg = lbs * 0.45359237;

    printf("%.4f lbs = %.4f kg.\n", lbs, kg);

    return 0;

}