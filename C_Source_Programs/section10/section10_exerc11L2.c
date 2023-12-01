#include <stdio.h>

// Functions prototype
void data_input(int arrayNum[], int size);
void print_address(int arrayNum[], int size);

int main() {

    int arrayNum[5], size = sizeof(arrayNum) / sizeof(arrayNum[0]);

    data_input(arrayNum, size);

    print_address(arrayNum, size);

    return 0;

}

void data_input(int arrayNum[], int size) {

    printf("*** DATA INPUT ***\n\n");
    
    printf("Fill in the elements' values of the array in the positions below:\n\n");
    
    for(int i = 0; i < size; i++) {
        printf("-> arrayNum[%d]: ", (i+1));
        scanf("%d", &arrayNum[i]);
    }

}

void print_address(int arrayNum[], int size) {

    int countEven = 0;

    printf("\n*** PRINT OF THE ADDRESSES OF THE VALUES OF THE EVEN ELEMENTS ***\n\n");
    
    for(int i = 0; i < size; i++) {
        if(arrayNum[i] % 2 == 0) {
            printf("-> arrayNum[%d]: %d | Address: %p\n", i, *(arrayNum + i), (void *)(arrayNum + i));
            countEven++;
        }   
    }

    if(countEven == 0) {
        printf("There are no even elements in this array.\n");
    }

}