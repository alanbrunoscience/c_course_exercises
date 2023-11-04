#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int bingoCard[5][5], size = sizeof(bingoCard) / sizeof(bingoCard[0]);
    int usedNumbers[100] = {0}; // Array to keep track of used numbers, initialized to 0

    printf("*** BINGO CARD ***\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            int random_number;
            do {
                random_number = (rand() % 99) + 1; // Generate a random number between 1 and 99
            } while(usedNumbers[random_number]); // Continue generating until a unique number is found

            bingoCard[i][j] = random_number;
            usedNumbers[random_number] = 1; // Mark the number as used

            printf("%d ", bingoCard[i][j]);

        }
        printf("\n");
    }

    return 0;
}