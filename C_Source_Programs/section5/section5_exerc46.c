#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

    // Seed the random number generator with the current time
    srand(time(NULL));

    int random_number = (rand() % 1000) + 1, number, count = 0;

    // printf("%d\n", random_number);

    printf("What's the random number generated?\n");
    scanf("%d", &number);
    count++;

    while(number != random_number) {
        if(number < random_number) {
            printf("The number that you input is smaller than the random number generated. Enter a new number, please:\n");
            scanf("%d", &number);
            count++;
        } else if (number > random_number) {
            printf("The number that you input is greater than the random number generated. Enter a new number, please:\n");
            scanf("%d", &number);
            count++;
        }
    }

    printf("You got the generated number right. The random number generated was %d and you entered %d. Congratulations!\n", random_number, number);

    return 0;

}