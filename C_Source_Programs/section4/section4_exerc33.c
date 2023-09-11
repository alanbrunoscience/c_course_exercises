#include <stdio.h>

int main(){

    float oldPrice;
    
    printf("Enter the product price ($), please:\n");
    scanf("%f", &oldPrice);

    if(oldPrice < 50.0) {
        printf("The new price is $ %.2f.\n", (oldPrice * 1.05));
    } else if(oldPrice >= 50.0 && oldPrice <= 100.0) {
        printf("The new price is $ %.2f.\n", (oldPrice * 1.10));
    } else {
        printf("The new price is $ %.2f.\n", (oldPrice * 1.15));
    }

    return 0;

}