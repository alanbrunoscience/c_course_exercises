#include <stdio.h>
#include <math.h>

int main() {

    float x, y, dist;

    printf("Enter the x value, please:\n");
    scanf("%f", &x);

    printf("Enter the y value, please:\n");
    scanf("%f", &y);

    dist = sqrt(pow(x,2) + pow(y,2));

    printf("The distance between %.2f and %.2f, from origin is %.2f.\n", x, y, dist);

    return 0;

}