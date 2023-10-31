#include <stdio.h>

int main() {

    int a, b, arrayA[4], countA = 0, arrayB[4], countB = 0, size = sizeof(arrayA) / sizeof(arrayA[0]);

    // Data Input
    printf("Enter the first integer number, please:\n");
    scanf("%d", &a);

    while(a <= 0 || a >= 10000) {
        printf("\nThe %d is invalid once it needs to be equal or greater than 1 and smaller than 10000. Enter a new number again:\n-> ", a);
        scanf("%d", &a);
        printf("\n");
    }

    printf("Enter the second integer number, please:\n");
    scanf("%d", &b);
    
    while(b <= 0 || b >= 10000) {
        printf("\nThe %d is invalid once it needs to be equal or greater than 1 and smaller than 10000. Enter a new number again:\n-> ", b);
        scanf("%d", &b);
        printf("\n");
    }

    while(a != 0) {
        arrayA[countA] = (a % 10);
        a /= 10;
        countA++;
    }

    while(b != 0) {
        arrayB[countB] = (b % 10);
        b /= 10;
        countB++;
    }

    // Data Output
    printf("-> Array A: ");
    for(int i = 0; i < countA; i++) {
        printf("%d ", arrayA[i]);
    }
    printf("\n");

    printf("-> Array B: ");
    for(int i = 0; i < countB; i++) {
        printf("%d ", arrayB[i]);
    }
    printf("\n");

    if(countA > countB) {
        int size = countA;
        for(int i = (countB); i < (countA); i++) {
            arrayB[i] = 0;
        }
    } else {
        int size = countB;
        for(int i = (countA); i < (countB); i++) {
            arrayA[i] = 0;
        }
    }

    printf("-> A + B: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", (arrayA[i] + arrayB[i]));
        if(i == (size - 1)) {
            printf("\n");
        }
    }

    return 0;

}
