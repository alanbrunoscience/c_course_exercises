#include <stdio.h>

int main(){

    float tempCelsius, tempKelvin;

    printf("Enter the temperature in Celsius degrees, please:\n");
    scanf("%f", &tempCelsius);

    tempKelvin = tempCelsius + 273.15;

    printf("The temperature in Kelvin degrees is %.2f\n", tempKelvin);

    return 0;

}