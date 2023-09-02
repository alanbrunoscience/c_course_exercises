#include <stdio.h>

int main(){

    float brazReal, usDollar, finalValue;

    printf("Enter the amount in brazilian real (R$), please:\n");
    scanf("%f", &brazReal);

    printf("Enter the current US dollar ($) value, please:\n");
    scanf("%f", &usDollar);

    finalValue = brazReal / usDollar;

    printf("The total amount in US dollars is $%.2f\n", finalValue);

    return 0;

}