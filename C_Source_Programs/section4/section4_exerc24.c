#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    float priceProd, newPrice;
    char state[2], lcState[2];

    printf("Enter the product price, please:\n");
    scanf("%f", &priceProd);

    printf("Enter the state abbreviation to the product sold (MG, SP, RJ or MS), please:\n");
    scanf("%s", state);

    for(int i = 0; i < strlen(state); i++){
        state[i] = tolower(state[i]);
    }

    while(strcmp(state, "mg") != 0 && strcmp(state, "sp") != 0 && strcmp(state, "rj") != 0 && strcmp(state, "ms") != 0){

        printf("\n*** The entered state is not valid. It is necessary to inform some states, such as: 'MG', 'SP', 'RJ' or 'MS'. You have to get into some of these states. Enter the state information again: ***\n");
        scanf("%s", state);

        for(int i = 0; i < strlen(state); i++){
            state[i] = tolower(state[i]);
        }

    }

    if(strcmp(state, "mg") == 0){
        newPrice = priceProd * 1.07;
    } else if (strcmp(state, "sp") == 0){
        newPrice = priceProd * 1.12;
    } else if (strcmp(state, "rj") == 0){
        newPrice = priceProd * 1.15;
    } else {
        newPrice = priceProd * 1.08;
    }

    printf("The new product price is $ %.2f.\n", newPrice);

    return 0;

}