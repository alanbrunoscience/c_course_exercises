#include <stdio.h>
#include <math.h>

int main() {

    int i = 1;
    float num;

    do {

        printf("Enter the %dº value, please:\n", i);
        scanf("%f", &num);

        if(num <= 0) {
            break;
        }

        printf("\n*** CALCULATIONS ***\n\n");
        printf("=> %.2f² = %.2f\n", num, pow(num, 2));
        printf("=> %.2f³ = %.2f\n", num, pow(num, 3));
        printf("=> %.2f³ = %.2f\n\n", num, sqrt(num));
        printf("======================\n\n");

        i++;

    } while(num > 0);

    printf("Finishing the program...\n");

    return 0;

}