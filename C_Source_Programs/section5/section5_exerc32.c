#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(NULL));

    int numOfRounds, numOnDice[2];

    printf("Enter the number of rounds to roll the dice, please:\n");
    scanf("%d", &numOfRounds);

    for(int i = 0; i < numOfRounds; i++) {
        
        int random_number1 = (rand() % 6) + 1;
        int random_number2 = (rand() % 6) + 1;

        numOnDice[0] = random_number1;
        numOnDice[1] = random_number2;

        printf("\n*** %dº ROUND ***\n\n", (i+1));

        if(numOnDice[0] > numOnDice[1]) {
            printf("-> D1: %d;\n", numOnDice[0]);
            printf("-> D2: %d;\n\n", numOnDice[1]);
            printf("The value in D1 is greater than the value in D2.\n\n");
        } else if(numOnDice[0] == numOnDice[1]) {
            printf("-> D1: %d;\n", numOnDice[0]);
            printf("-> D2: %d;\n\n", numOnDice[1]);
            printf("The value in D1 is equal to the value in D2.\n\n");
        } else {
            printf("-> D1: %d;\n", numOnDice[0]);
            printf("-> D2: %d;\n\n", numOnDice[1]);
            printf("The value in D2 is greater than the value in D1.\n\n");
        }

    }

    return 0;

}