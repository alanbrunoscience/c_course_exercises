#include <stdio.h>

int main(){

    float kg, lbs;

    printf("Enter the mass in kilograms (kg), please:\n");
    scanf("%f", &kg);

    lbs = kg / 0.45359237;

    printf("%.4f kg = %.4f lbs.\n", kg, lbs);

    return 0;

}