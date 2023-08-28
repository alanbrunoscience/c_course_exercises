#include <stdio.h>

int main(){

    float kilometers, miles;

    printf("Enter the distance in Kilometers, please:\n");
    scanf("%f", &kilometers);

    miles = kilometers / 1.61;

    printf("%.2f kilometers = %.2f miles.\n", kilometers, miles);

    return 0;

}