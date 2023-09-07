#include <stdio.h>
#include <stdlib.h> // Required for rand() and srand()
#include <time.h>   // Required for time()
#include <unistd.h>  // Required for sleep()

int main() {

    int ranNum[5], ranNum2[5];

    // Seed the random number generator with the current time
    srand(time(NULL));

    printf("*** QUESTIONS ***\n\n");

    // Generate and print 5 random numbers between 0 and 99
    for (int i = 0; i < 5; i++) {
        int randomNumber = rand() % 101; // Generate a random number between 0 and 99
        int randomNumber2 = rand() % 101;
        printf("%dº) %d + %d = ?;\n", (i + 1), randomNumber, randomNumber2);
        ranNum[i] = randomNumber;
        ranNum2[i] = randomNumber2;
    }

    sleep(10);

    printf("\n*** ANSWERS ***\n\n");

    for (int i = 0; i < 5; i++) {
        printf("%dº) %d + %d = %d;\n", (i + 1), ranNum[i], ranNum2[i], (ranNum[i] + ranNum2[i]));
    }

    return 0;
}