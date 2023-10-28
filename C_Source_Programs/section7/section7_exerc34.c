#include <stdio.h>

int main() {

    int arrayA[5], arrayB[5], size = sizeof(arrayA) / sizeof(arrayA[0]), minor = 0, temp = 0, c[5], countC = 0;

    // Data Input
    printf("*** ARRAY A ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("Enter the %dº number, please: ", (i+1));
        scanf("%d", &arrayA[i]);
    }

    // Sorting the array A
    for(int i = 0; i < size; i++) {
        minor = i;
        for(int j = i + 1; j < size; j++) {
            if(arrayA[j] < arrayA[minor]) {
                minor = j;
            }
        }
        temp = arrayA[i];
        arrayA[i] = arrayA[minor];
        arrayA[minor] = temp;
    }

    // Data Input
    printf("\n*** ARRAY B ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("Enter the %dº number, please: ", (i+1));
        scanf("%d", &arrayB[i]);
    }

    // Sorting the array B
    for(int i = 0; i < size; i++) {
        minor = i;
        for(int j = i + 1; j < size; j++) {
            if(arrayB[j] < arrayB[minor]) {
                minor = j;
            }
        }
        temp = arrayB[i];
        arrayB[i] = arrayB[minor];
        arrayB[minor] = temp;
    }

    printf("\n*** SORTED ARRAY A ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("A[%d]: %d\n", i, arrayA[i]);
    }

    printf("\n*** SORTED ARRAY B ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("B[%d]: %d\n", i, arrayB[i]);
    }

    printf("\n*** RESULTS ***\n\n");

    printf("-> A + B: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", (arrayA[i] + arrayB[i]));
        if(i == (size - 1)) {
            printf("\n");
        }
    }
    
    printf("-> A x B: ");
    for(int i = 0; i < size; i++) { 
        printf("%d ", (arrayA[i] * arrayB[i]));
        if(i == (size - 1)) {
            printf("\n");
        }
    }

    printf("-> A - B: ");
    // Find elements in A that is not in B
    for(int i = 0; i < size; i++) {
        short findNum = 0;
        for(int j = 0; j < size; j++) {
            if(arrayA[i] == arrayB[j]) {
                findNum = 1;
                break;
            }
        }
        if(!findNum) {
            c[countC] = arrayA[i];
            countC++;
        }
    }

    for(int i = 0; i < countC; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    printf("-> A ∩ B: ");
    int arrayABI[size], countABI = 0;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(arrayA[i] == arrayB[j]) {
                arrayABI[countABI] = arrayA[i];
                countABI++;
            }
        }
    }

    for(int i = 0; i < countABI; i++) {
        printf("%d ", arrayABI[i]);
    }
    printf("\n");

    printf("-> A ∪ B (sorted array and without duplications): ");

    int arrayABU[size * 2], countABU = 0;

    for(int i = 0; i < size; i++) {
        arrayABU[i] = arrayA[i];
        countABU++;
    }

    for(int i = countABU; i < (size * 2); i++) {
        arrayABU[i] = arrayB[i - 5];
    }

    // Sorting the Array
    for(int i = 0; i < (size * 2); i++) {
        minor = i;
        for(int j = i + 1; j < (size * 2); j++) {
            if(arrayABU[j] < arrayABU[minor]) {
                minor = j;
            }
        }
        temp = arrayABU[i];
        arrayABU[i] = arrayABU[minor];
        arrayABU[minor] = temp;
    }

    int newArrayU[size * 2], countU = 0;

    // Removing Duplicate Elements
    for(int i = 0; i < (size * 2); i++) {
        if(arrayABU[i] != arrayABU[i+1]) {
            newArrayU[countU] = arrayABU[i];
            countU++;
        }
    }

    for(int i = 0; i < countU; i++) {
        printf("%d ", newArrayU[i]);
    }
    printf("\n");

    return 0;

}