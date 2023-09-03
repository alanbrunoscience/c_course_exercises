#include <stdio.h>
#include <math.h>

int main() {

    float number;

    do {
        printf("Enter a positive number, please:\n");
        scanf("%f", &number);

        if (number > 0) {
            printf("The square root of %.2f is %.2f.\n", number, (sqrt(number)));
        } else {
            printf("*** The number is invalid. You must enter a positive number! ***\n\n");
        }
    } while (number < 0);

    return 0;
}