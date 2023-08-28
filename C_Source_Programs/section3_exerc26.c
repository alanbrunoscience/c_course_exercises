#include <stdio.h>

int main(){

    float areaM2, hectare;

    printf("Enter the area in square meters, please:\n");
    scanf("%f", &areaM2);

    hectare = areaM2 * 0.0001;

    printf("%.4f m² = %.4f ha\n", areaM2, hectare);

    return 0;

}