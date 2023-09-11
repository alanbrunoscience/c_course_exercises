#include <stdio.h>
#include <string.h>

int main() {

    int code, quantity; 
    float price, totalPrice;
    char product[20];

    printf("Enter the product code, please:\n");
    scanf("%d", &code);

    printf("Enter the quantity of product, please:\n");
    scanf("%d", &quantity);

    switch (code)
    {
    case 100:
        strcpy(product, "Hot Dog");
        price = 1.20;
        break;
    case 101:
        strcpy(product, "Simple Bauru");
        price = 1.30;
        break;
    case 102:
        strcpy(product, "Bauru with Egg");
        price = 1.50;
        break;
    case 103:
        strcpy(product, "Hamburguer");
        price = 1.20;
        break;
    case 104:
        strcpy(product, "Cheeseburguer");
        price = 1.70;
        break;
    case 105:
        strcpy(product, "Juice");
        price = 2.20;
        break;    
    default:
        strcpy(product, "Soft Drink");
        price = 1.00;
    }

    totalPrice = price * quantity;

    printf("The price to be paid for %d %s(s) is $ %.2f.\n", quantity, product, totalPrice);

    return 0;

}