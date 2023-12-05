#include <stdio.h>
#include <stdlib.h>

// Functions prototype
int array_size_input(int *size);
void fill_elements_array(int **array_ptr, int *size);
void print_array_elements(int *array_ptr, int *size);
void print_array_elements_plus_one(int *array_ptr, int *size);

int main() {

    int size;

    array_size_input(&size);

    int array_integers[size];
    int *array_ptr = array_integers;

    fill_elements_array(&array_ptr, &size);
    print_array_elements(array_ptr, &size);
    print_array_elements_plus_one(array_ptr, &size);

    return 0;

}

int array_size_input(int *size) {

    printf("*** DATA INPUT ***\n\n");
    printf("Enter the size of the array: ");
    scanf("%d", size);

    while(*size <= 0) {
        printf("\nThe size is invalid! Enter a new size again: ");
        scanf("%d", size);
    }

    return *size;

}

void fill_elements_array(int **array_ptr, int *size) {

    // Input of the elements' values of the array
    printf("\n*** FILL THE ELEMENTS OF THE ARRAY ***\n\n");
    printf("-> Fill in the elements' values of the array in the positions below:\n\n");
    for(int i = 0; i < *size; i++) {
        printf("array_ptr[%d]: ", i);
        scanf("%d", (*array_ptr + i));
    }

}

void print_array_elements(int *array_ptr, int *size) {
    
    printf("\n*** PRINT ARRAY ELEMENTS ***\n\n");
    for(int i = 0; i < *size; i++) {
        printf("%d ", *(array_ptr + i));
    }

    putchar('\n');

}

void print_array_elements_plus_one(int *array_ptr, int *size) {

    printf("\n*** PRINT ARRAY ELEMENTS PLUS ONE ***\n\n");
    for(int i = 0; i < *size; i++) {
        printf("%d ", (*(array_ptr + i) + 1));
    }

    putchar('\n');

}