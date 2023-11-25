#include <stdio.h>
#include <math.h>

// Functions prototype
void doubleNumbers(int arrayNum[], int size);
void printNewValues(int arrayNum[], int size);

int main() {

    int arrayNum[5], size = sizeof(arrayNum) / sizeof(arrayNum[0]);

    for(int i = 0; i < size; i++) {
        printf("Enter the %dº value, please:\n", (i+1));
        scanf("%d", &arrayNum[i]);
    }

    doubleNumbers(arrayNum, size);

    printNewValues(arrayNum, size);

}

void doubleNumbers(int arrayNum[], int size) {
    
    for(int i = 0; i < size; i++) {
        arrayNum[i] = *(arrayNum + i) * 2;
    }

}

void printNewValues(int arrayNum[], int size) {

    printf("\n\n*** SQUARED VALUES ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("arrayNum[%d]: %d\n", i, *(arrayNum + i));
    }

}