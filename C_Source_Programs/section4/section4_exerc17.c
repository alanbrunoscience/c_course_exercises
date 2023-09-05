#include <stdio.h>

int main(){

    float majorBase, minorBase, height, area;

    do {
        printf("Enter the major base value, please:\n");
        scanf("%f", &majorBase);

        printf("Enter the minor base value, please:\n");
        scanf("%f", &minorBase);

        printf("Enter the height value, please:\n");
        scanf("%f", &height);

        if(majorBase <= 0.0 || minorBase <= 0.0 || height <= 0.0){
            printf("\n*** Major base, minor base, and height must be greater than 0! ***\n\n");
        }

    } while(majorBase <= 0.0 || minorBase <= 0.0 || height <= 0.0);

    area = ((majorBase + minorBase) * height) / 2.00;

    printf("\nThe trapeze area is %.2f.\n", area);

    return 0;

}