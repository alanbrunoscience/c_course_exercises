#include <stdio.h>

int main(){

    float acres, areaM2;

    printf("Enter the area in acres (ac), please:\n");
    scanf("%f", &acres);

    areaM2 = acres * 4046.856422;

    printf("%.4f ac = %.4f m².\n", acres, areaM2);

    return 0;

}