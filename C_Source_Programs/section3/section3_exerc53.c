#include <stdio.h>

int main(){

    float length, width, price, perimeter, totalPrice;

    printf("Enter the land length (m), please:\n");
    scanf("%f", &length);
    fflush(stdin);

    printf("Enter the land width (m), please:\n");
    scanf("%f", &width);
    fflush(stdin);

    printf("Enter fabric meter price to fence the land, please:\n");
    scanf("%f", &price);
    fflush(stdin);

    perimeter = 2 * length + 2 * width;

    totalPrice = price * perimeter;

    printf("The total cost to fence the land is $ %.2f.\n", totalPrice);

    return 0;

}