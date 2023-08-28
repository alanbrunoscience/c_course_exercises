#include <stdio.h>
#include <math.h>

int main(){

    float radius, area, pi = 3.141592;

    printf("Enter the radius value in centimeters (cm), please:\n");
    scanf("%f", &radius);

    area = pi * pow(radius, 2);

    printf("The circle area is %.2f cm².\n", area);

    return 0;

}