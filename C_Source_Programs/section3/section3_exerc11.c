#include <stdio.h>

int main(){

    float speedMs, speedKmh;

    printf("Enter speed in m/s, please:\n");
    scanf("%f", &speedMs);

    speedKmh = speedMs * 3.6;

    printf("%.2f m/s = %.2f Km/h\n", speedMs, speedKmh);

    return 0;

}