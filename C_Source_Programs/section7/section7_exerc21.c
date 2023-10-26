#include <stdio.h>

int main() {

    int a[5], newA[5], b[5], newB[5], c[5], size = sizeof(a)/sizeof(a[0]), minor, temp, countA = 0, countB = 0, countC = 0;
    

    // Enter elements in array A
    printf("*** ARRAY A ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("Enter the %dº number, please: ", (i+1));
        scanf("%d", &a[i]);
    }

    // Sorting the array A
    for(int i = 0; i < size; i++) {
        minor = i;
        for(int j = i + 1; j < size; j++) {
            if(a[j] < a[minor]) {
                minor = j;
            }
        }
        temp = a[i];
        a[i] = a[minor];
        a[minor] = temp;
    }

    // Removing duplicate elements in A
    for(int i = 0; i < size; i++) {
        if(a[i] != a[i+1]) {
            newA[countA] = a[i];
            countA++;
        }
    }

    //====================================================================================================================================

    // Enter elements in array B
    printf("\n\n*** ARRAY B ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("Enter the %dº number, please: ", (i+1));
        scanf("%d", &b[i]);
    }

    // Sorting the array B
    for(int i = 0; i < size; i++) {
        minor = i;
        for(int j = i + 1; j < size; j++) {
            if(b[j] < b[minor]) {
                minor = j;
            }
        }
        temp = b[i];
        b[i] = b[minor];
        b[minor] = temp;
    }

    // Removing duplicate elements in B
    for(int i = 0; i < size; i++) {
        if(b[i] != b[i+1]) {
            newB[countB] = b[i];
            countB++;
        }
    }

    // Find elements in A that is not in B
    for(int i = 0; i < countA; i++) {
        short findNum = 0;
        for(int j = 0; j < countB; j++) {
            if(newA[i] == newB[j]) {
                findNum = 1;
                break;
            }
        }
        if(!findNum) {
            c[countC] = newA[i];
            countC++;
        }
    }

    printf("\n*** ARRAY A ***\n\n");
    for(int i = 0; i < countA; i++) {
        printf("newA[%d]: %d\n", i, newA[i]);
    }

    printf("\n*** ARRAY B ***\n\n");
    for(int i = 0; i < countB; i++) {
        printf("newB[%d]: %d\n", i, newB[i]);
    }

    printf("\n*** C = A - B ***\n\n");
    for(int i = 0; i < countC; i++) {
        printf("c[%d]: %d\n", i, c[i]);
    }

    return 0;

}