#include <stdio.h>

int main () {

    int year = 1996, currentYear = 2023;
    double salary = 2000;
    float increasePercentage = 0.015;

    while(year <= currentYear) {
        salary *= (1.0 + increasePercentage);
        increasePercentage *= 2;
        year++;
    }

    printf("The current salary in %d is $ %.2lf.\n", currentYear, salary);

    return 0;

}