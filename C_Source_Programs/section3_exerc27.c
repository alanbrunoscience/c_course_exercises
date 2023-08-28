#include <stdio.h>

int main(){

    float hectare, areaM2;

    printf("Enter the area in hectare (ha), please:\n");
    scanf("%f", &hectare);

    areaM2 = hectare * 10000;

    printf("%.4f ha = %.4f m².\n", hectare, areaM2);

    return 0;

}