#include <stdio.h>

int main(){

    float areaM2, acres;

    printf("Enter the area in square meters (m²), please:\n");
    scanf("%f", &areaM2);

    acres = areaM2 * 0.000247;

    printf("%.4f m² = %.4f ac\n", areaM2, acres);

    return 0;

}