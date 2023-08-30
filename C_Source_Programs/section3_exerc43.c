#include <stdio.h>

int main(){

    float price;

    printf("Enter the dollar amount ($), please:\n");
    scanf("%f", &price);

    printf("-> Total payable with 10%% discount: $ %.2f\n", (price * 0.90));
    printf("-> Value of each installment, 3 installments without interest: $ %.2f\n", (price / 3.0));
    printf("-> Seller's commission (cash payment): $ %.2f\n", ((price * 0.90) * 0.05));
    printf("-> Seller's commission (payment in installments): $ %.2f\n", (price * 0.05));

    return 0;

}