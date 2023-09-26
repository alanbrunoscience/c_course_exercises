#include <stdio.h>

int main() {

    float base, height, area = 0;

    do {

        printf("Enter the triangle base (cm), please:\n");
        scanf("%f", &base);

        printf("Enter the triangle height (cm), please:\n");
        scanf("%f", &height);

        if(base <= 0 || height <= 0) {
            printf("\n *** The base and height values need to be greater than 0. Enter the values again, please. ***\n\n");
        }

    } while(base <= 0 || height <= 0);

    area = (base * height) / 2;

    printf("The triangle area is %.2f cm².\n", area);

    return 0;

}