#include <stdio.h>

int main() {
    int num, sumDiv = 0;
    int first = 1; // Flag to determine if it's the first number to print

    do {
        printf("Enter an integer number greater than 0, please:\n");
        scanf("%d", &num);

        if (num < 1) {
            printf("\n*** This is not a valid number. The number needs to be greater than 0. Enter a new number again ***\n\n");
        }

    } while (num < 1);

    for (int i = 1; i <= num; i++) {
        if (num % i == 0 && i != num) { // Exclude the entered number from the sum and output
            if (first) {
                printf("%d", i);
                first = 0;
            } else {
                printf(" + %d", i);
            }
            sumDiv += i;
        }
    }

    printf(" = %d\n", sumDiv);

    return 0;
}
