#include <stdio.h>
#include <math.h>

int main(){

    float height, radius, volume, pi = 3.141592653589793238462643383279502884197;

    printf("Enter the cylinder height (cm), please:\n");
    scanf("%f", &height);
    printf("Enter the cylinder radius (cm), please:\n");
    scanf("%f", &radius);

    volume = pi * pow(radius, 2) * height;

    printf("The cylinder volume is %.2f cm³.\n", volume);

    return 0;

}