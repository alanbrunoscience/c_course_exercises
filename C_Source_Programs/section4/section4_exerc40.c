#include <stdio.h>

int main() {

    float costFactory;

    printf("Enter with the car's cost factory, please:\n");
    scanf("%f", &costFactory);

    if(costFactory < 12000){
        printf("*** COST TO THE CONSUMER ***\n-> %% of Distributor: $ %.2f\n-> %% of Taxes: Free\n-> Final Cost: $ %.2f\n", (costFactory * 0.05), (costFactory * 1.05));
    } else if(costFactory >= 12000 && costFactory <= 25000){
        printf("*** COST TO THE CONSUMER ***\n-> %% of Distributor: $ %.2f\n-> %% of Taxes: $ %.2f\n-> Final Cost: $ %.2f\n", (costFactory * 0.10), (costFactory * 0.15), (costFactory * 1.25));
    } else {
        printf("*** COST TO THE CONSUMER ***\n-> %% of Distributor: $ %.2f\n-> %% of Taxes: $ %.2f\n-> Final Cost: $ %.2f\n", (costFactory * 0.15), (costFactory * 0.20), (costFactory * 1.35));
    }

    return 0;

}