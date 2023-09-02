#include <stdio.h>

int main(){

    float rad, degrees, pi = 3.14159265358979323846;
    
    printf("Enter the angle in radians, please:\n");
    scanf("%f", &rad);

    degrees = rad * 180.0 / pi;

    printf("%.4f rad = %.4f degrees.\n", rad, degrees);

    return 0;

}