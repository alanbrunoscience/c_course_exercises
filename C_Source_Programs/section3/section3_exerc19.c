#include <stdio.h>

int main(){

    float liters, meters3;

    printf("Enter the volume in liters, please:\n");
    scanf("%f", &liters);

    meters3 = liters/1000.0;

    printf("%.4f liters = %.4f m³.\n", liters, meters3);

    return 0;

}