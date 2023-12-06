#include <stdio.h>
#include <stdlib.h>

// Functions prototype
int array_size_input(int *size1, int *size2);
void fill_array_elements(int **array1_ptr, int **array2_ptr, int *size1);
void sum_array_elements(int *array1_ptr, int *array2_ptr, int **array3_ptr, int *size1);
int memory_alloc_validation(int *array);
void print_new_array_elements(int *array1_ptr, int *array2_ptr, int *array3_ptr, int *size1);

int main() {

    int size1, size2;
    
    int ret_function;

    while(!(ret_function = array_size_input(&size1, &size2))) {
        array_size_input(&size1, &size2);
    }

    int array1[size1], array2[size2];
    int *array1_ptr = array1, *array2_ptr = array2, *array3_ptr;

    fill_array_elements(&array1_ptr, &array2_ptr, &size1);
    sum_array_elements(array1_ptr, array2_ptr, &array3_ptr, &size1);
    print_new_array_elements(array1_ptr, array2_ptr, array3_ptr, &size1);

    return 0;
    
}

int array_size_input(int *size1, int *size2) {

    int size_values[2], length_size = sizeof(size_values) / sizeof(size_values[0]);    

    printf("*** DATA INPUT ***\n\n");
    for(int i = 0; i < length_size; i++) {
        printf("%d) Enter the size of the %dº array: ", (i+1), (i+1));
        scanf("%d", &size_values[i]);

        while(size_values[i] <= 0) {
            printf("\n-> The size is invalid! Enter a new size for the %dº array again: ", (i+1));
            scanf("%d", &size_values[i]);
        }

        putchar('\n');

    }

    *size1 = size_values[0];
    *size2 = size_values[1];

    if(*size1 != *size2) {
        printf("*** The array sizes are different. You must enter the same size value for both arrays. ***\n\n");
        return 0;
    } else {
        return 1;
    }

}

void fill_array_elements(int **array1_ptr, int **array2_ptr, int *size1) {

    printf("*** FILL THE ELEMENTS OF THE ARRAY ***\n\n");

    printf("-> Fill in the elements' values of the array in the positions below:\n\n");
    
    printf("*** 1º ARRAY ***\n\n");
    for(int i = 0; i < *size1; i++) {
        printf("array1_ptr[%d]: ", i);
        scanf("%d", (*array1_ptr + i));
    }

    printf("\n*** 2º ARRAY ***\n\n");
    for(int i = 0; i < *size1; i++) {
        printf("array2_ptr[%d]: ", i);
        scanf("%d", (*array2_ptr + i));
    }

}

void sum_array_elements(int *array1_ptr, int *array2_ptr, int **array3_ptr, int *size1) {
    
    // Allocate memory dynamically for the array3
    *array3_ptr = (int *)malloc(*size1 * sizeof(int));

    // Validate memory allocation
    if(memory_alloc_validation(*array3_ptr)) {
        exit(1);
    }

    // The sum of the elements of array1_ptr and array2_ptr
    for(int i = 0; i < *size1; i++) {
        *(*array3_ptr + i) = *(array1_ptr + i) + *(array2_ptr + i);
    }

}

int memory_alloc_validation(int *array) {
    if(array == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }
    return 0;
}

void print_new_array_elements(int *array1_ptr, int *array2_ptr, int *array3_ptr, int *size1) {

    printf("\n*** ARRAY A + ARRAY B = ARRAY C ***\n\n");
    printf("-> array1_ptr: |");
    for(int i = 0; i < *size1; i++) {
        printf(" %d |", *(array1_ptr + i));
    }

    putchar('\n');

    printf("-> array2_ptr: |");
    for(int i = 0; i < *size1; i++) {
        printf(" %d |", *(array2_ptr + i));
    }

    putchar('\n');

    printf("-> array3_ptr: |");
    for(int i = 0; i < *size1; i++) {
        printf(" %d |", *(array3_ptr + i));
    }
    
    putchar('\n');

}