#include <stdio.h>

int main(){

    float tempCelsius, tempFahren;

    printf("Enter the temperature in degrees Celsius, please:\n");

    scanf("%f", &tempCelsius);

    tempFahren = tempCelsius * (9.0 / 5.0) + 32.0;

    printf("%.2fºC = %.2fºF\n", tempCelsius, tempFahren);

    return 0;

}