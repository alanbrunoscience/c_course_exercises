#include <stdio.h>

int main(){

    float meters3, liters;

    printf("Enter the volume in meters cubics, please:\n");
    scanf("%f", &meters3);

    liters = 1000.0 * meters3;

    printf("%.2f m³ = %.2f L.\n", meters3, liters);

    return 0;

}