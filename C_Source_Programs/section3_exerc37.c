#include <stdio.h>

int main(){

    float price, newPrice;

    printf("Enter the product price ($), please:\n");
    scanf("%f", &price);

    newPrice = price * 0.88;

    printf("The new product price with a 12%% discount is $%.2f.\n", newPrice);

    return 0;

}