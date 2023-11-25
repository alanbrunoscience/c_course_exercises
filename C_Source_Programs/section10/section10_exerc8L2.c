#include <stdio.h>

// Functions prototype
void dataInput(float arrayNum[], int size);
void printElementsAddress(float arrayNum[], int size);

int main() {

    float arrayNum[10];
    int size = sizeof(arrayNum) / sizeof(arrayNum[0]);

    dataInput(arrayNum, size);

    printElementsAddress(arrayNum, size);

    return 0;

}

void dataInput(float arrayNum[], int size) {
    
    for (int i = 0; i < size; i++) {
        printf("Enter the %dº element's value, please: ", (i+1));
        scanf("%f", &arrayNum[i]);
    }

}

void printElementsAddress(float arrayNum[], int size) {

    printf("\n\n*** ARRAY ELEMENTS' VALUES AND THEIR ADDRESS ***\n\n");
    for (int i = 0; i < size; i++) {
        // printf("-> arrayNum[%d]: %.2f / Address: %p\n", i, *(arrayNum + i), (void *)(arrayNum + i));
        printf("-> arrayNum[%d]: %.2f / Address: %p\n", i, *(arrayNum + i), (void *)&arrayNum[i]);
    }

}