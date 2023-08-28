#include <stdio.h>

int main(){

    float distM, distKm;

    printf("Enter distance in miles, please:\n");
    scanf("%f", &distM);

    distKm = 1.61 * distM;

    printf("%.2f miles = %.2f kilometers.\n", distM, distKm);

    return 0;

}