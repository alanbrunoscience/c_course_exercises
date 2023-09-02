#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float a, b, hip;

    printf("Enter the first side value (cm), please:\n");
    scanf("%f", &a);

    printf("Enter the second side value (cm), please:\n");
    scanf("%f", &b);

    hip = sqrt(pow(a, 2) + pow(b, 2));

    printf("The hypotenuse value is %.2f cm.\n", hip);

    return 0;

}