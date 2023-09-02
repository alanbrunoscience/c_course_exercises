#include <stdio.h>

int main(){

    float number, pow;

    printf("Enter with a real number, please:\n");

    scanf("%f", &number);

    pow = number * number;

    printf("(%.2f)² = %.2f\n", number, pow);

    return 0;

}