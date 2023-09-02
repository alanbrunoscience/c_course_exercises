#include <stdio.h>

int main(){

    float centimeters, inches;

    printf("Enter the length in centimeters, please:\n");
    scanf("%f", &centimeters);

    inches = centimeters/2.54;

    printf("%.2f centimeters = %.2f inches.\n", centimeters, inches);

    return 0;

}