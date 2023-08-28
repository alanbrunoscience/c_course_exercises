#include <stdio.h>

int main(){

    float degrees, radians, pi = 3.14;

    printf("Enter the angle in degrees, please:\n");
    scanf("%f", &degrees);

    radians = degrees * pi/180;

    printf("%.4fº = %.4f rad.\n", degrees, radians);

    return 0;

}