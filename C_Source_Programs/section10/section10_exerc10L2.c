#include <stdio.h>

// Functions prototype
void dataInput(int arrayNum[], int size);
void printDoubleValues(int arrayNum[], int size);

int main() {

    int arrayNum[5], size = sizeof(arrayNum) / sizeof(arrayNum[0]);

    dataInput(arrayNum, size);

    printDoubleValues(arrayNum, size);

    return 0;

}

void dataInput(int arrayNum[], int size) {
    for(int i = 0; i < size; i++) {
        printf("Enter the %dº element's value, please: ", (i+1));
        scanf("%d", &arrayNum[i]);
    }
}

void printDoubleValues(int arrayNum[], int size) {

    printf("\n*** PRINT DOUBLE THE VALUE OF ELEMENTS ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("arrayNum[%d]: %d / %d * 2 = %d\n", i, *(arrayNum + i), *(arrayNum + i), (*(arrayNum + i) * 2));
    }

}