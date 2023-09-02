#include <stdio.h>

int main(){

    float meters, yards;

    printf("Enter the length in meters (m), please:\n");
    scanf("%f", &meters);

    yards = meters / 0.9144;

    printf("%.4f meters = %.4f pounds\n", meters, yards);

    return 0;

}