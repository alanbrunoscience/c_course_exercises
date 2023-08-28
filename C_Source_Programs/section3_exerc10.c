#include <stdio.h>

int main(){

    float speedKmh, speedMs;

    printf("Enter speed in Km/h, please:\n");
    scanf("%f", &speedKmh);

    speedMs = speedKmh / 3.6;

    printf("%.2f Km/h = %.2f m/s.\n", speedKmh, speedMs);

    return 0;

}