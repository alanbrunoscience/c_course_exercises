#include <stdio.h>

int main(){

    float num, fifthPart;

    printf("Enter with a real number, please:\n");

    scanf("%f", &num);

    fifthPart = num / 5;

    printf("%.2f / 5 = %.2f\n", num, fifthPart);

    return 0;

}