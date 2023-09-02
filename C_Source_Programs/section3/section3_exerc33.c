#include <stdio.h>

int main(){

    float length, area;

    printf("Inform the size length of a square in centimeters (cm), please:\n");
    scanf("%f", &length);

    area = length * length;

    printf("The square area is %.2f cm².\n", area);

    return 0;

}