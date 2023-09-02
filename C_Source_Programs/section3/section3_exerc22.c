#include <stdio.h>

int main(){

    float yards, meters;

    printf("Enter the length in yards (yd), please:\n");
    scanf("%f", &yards);

    meters = 0.9144 * yards;

    printf("%.4f yards (yd) = %.4f meters.\n", yards, meters);

    return 0;

}