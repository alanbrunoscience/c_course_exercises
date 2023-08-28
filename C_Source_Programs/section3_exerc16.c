#include <stdio.h>

int main(){

    float inches, centimeters;

    printf("Enter the length in inches, please:\n");
    scanf("%f", &inches);

    centimeters = inches * 2.54;

    printf("%.2f inches = %.2f centimeters.\n", inches, centimeters);

    return 0;

}