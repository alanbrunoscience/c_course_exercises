#include <stdio.h>

int main() {

    int arrayA[10], newA[10], arrayB[10], newB[10], size = sizeof(arrayA) / sizeof(arrayA[0]), minor, temp, countA = 0, countB = 0, countC = 0;

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

    // Removing duplicate elements in A
    for(int i = 0; i < size; i++) {
        if(arrayA[i] != arrayA[i+1]) {
            newA[countA] = arrayA[i];
            countA++;
        }
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

    // Removing duplicate elements in B
    for(int i = 0; i < size; i++) {
        if(arrayB[i] != arrayB[i+1]) {
            newB[countB] = arrayB[i];
            countB++;
        }
    }

    countC = countA + countB;
    int arrayC[countC];

    arrayC[0] = newA[0];
    for(int i = 2; i < countC; i+=2) {
        arrayC[i] = newA[i/2];
    }

    arrayC[1] = newA[1];
    for(int i = 1; i <= countC; i+=2) {
        arrayC[i] = newB[i/2];
    }

    printf("\n*** ARRAY A ***\n\n");
    for(int i = 0; i < countA; i++) {
        printf("newA[%d]: %d\n", i, newA[i]);
    }

    printf("\n*** ARRAY B ***\n\n");
    for(int i = 0; i < countB; i++) {
        printf("newB[%d]: %d\n", i, newB[i]);
    }

    printf("\n*** ARRAY C ***\n\n");
    for(int i = 0; i < countC; i++) {
        printf("arrayC[%d]: %d\n", i, arrayC[i]);
    }

    return 0;

}