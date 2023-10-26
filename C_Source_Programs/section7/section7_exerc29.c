#include <stdio.h>
#include <stdbool.h>

void sieveOfEratosthenes(int size, bool isPrime[]) {
    for (int i = 2; i <= size; i++) {
        isPrime[i] = true;
    }

    for (int p = 2; p * p <= size; p++) {
        if (isPrime[p] == true) {
            for (int i = p * p; i <= size; i += p) {
                isPrime[i] = false;
            }
        }
    }
}

int main() {
    int numbers[10], size = sizeof(numbers) / sizeof(numbers[0]);
    bool isPrime[size + 1];

    // Get user input
    for (int i = 0; i < size; i++) {
        printf("Enter the %dº integer number (numbers[%d]), please: ", (i+1), i);
        scanf("%d", &numbers[i]);
    }

    // Find prime numbers using Sieve of Eratosthenes
    sieveOfEratosthenes(size, isPrime);

    // Print prime numbers from the user input
    printf("\n*** PRIME NUMBERS AND ITS POSITIONS ON THE LIST ***\n\n");
    for (int i = 0; i < size; i++) {
        if (isPrime[numbers[i]]) {
            printf("-> Prime Number: %d | Position: %d (numbers[%d])\n", numbers[i], i, i);
        }
    }

    return 0;
}