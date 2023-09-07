#include <stdio.h>

int main (){

    float km, liters, consumption;

    printf("Enter the distance in kilometers (km) that you traveled, please:\n");
    scanf("%f", &km);

    printf("Enter the amount of fuel (liters) needed to fill up your car, please:\n");
    scanf("%f", &liters);

    consumption = km/liters;

    if(consumption < 8.0){
        printf("Your car is consuming too much fuel (%.2f km/l). Then we suggest that you sell your car.\n", consumption);
    } else if(consumption > 8.0 && consumption <= 14.0){
        printf("Your car is economical. It does %.2f km/l.\n", consumption);
    } else {
        printf("Your car is very economical. It does %.2f km/l.\n", consumption);
    }

    return 0;

}