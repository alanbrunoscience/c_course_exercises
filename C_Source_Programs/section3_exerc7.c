#include <stdio.h>

int main(){

    float tempFahren, tempCelsius;

    printf("Enter the temperature in degrees Fahrenheit, please:\n");

    scanf("%f", &tempFahren);

    tempCelsius = 5.0 * (tempFahren - 32.0) / 9.0;

    printf("%.2fºF = %.2fºC\n", tempFahren, tempCelsius);

    return 0;

}