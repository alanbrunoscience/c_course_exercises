#include <stdio.h>

int main(){

    int i = 0, j = 0, k = 0;
    float values[3], percentInvested[3], vTotal = 0, lotPrizeAmount, amountReceived;

    while(i < 3){

        printf("Enter %dº value invested ($), please:\n", (i+1));
        scanf("%f", &values[i]);
        fflush(stdin);
        vTotal += values[i];
        i++;
    }

    printf("Enter the lottery prize amount ($), please:\n");
    scanf("%f", &lotPrizeAmount);
    fflush(stdin);

    while(j < 3){
        percentInvested[j] = (100.0 * values[j]) / vTotal;
        j++;
    }

    printf("\n*** PRIZE DIVISION ***\n");
    while(k < 3){
        amountReceived = (lotPrizeAmount * percentInvested[k]) / 100.0;
        printf("=> The %dº lottery player will receive $ %.2f, corresponding to %.2f %%.\n", (k + 1), amountReceived, percentInvested[k]);
        k++;
    }

    return 0;

}