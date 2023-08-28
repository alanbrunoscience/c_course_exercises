#include <stdio.h>

int main(){

    float tempKelvin, tempCelsius;

    printf("Enter the temperature in Kelvin degrees, please:\n");
    scanf("%f", &tempKelvin);

    tempCelsius = tempKelvin - 273.15;

    printf("The temperature in Celsius degrees is %.2fºC\n", tempCelsius);

    return 0;

}