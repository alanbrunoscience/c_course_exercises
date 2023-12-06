#include <stdio.h>
#include <stdlib.h>

// Functions prototype
int array_size_input(int *size);
void fill_array_elements(int **array_ptr, int *size);
int find_biggest_element(int *array_ptr, int *size);
void print_array_elements(int *array_ptr, int *size, int major_element);

int main() {

    int size;

    array_size_input(&size);

    int array[size];
    int *array_ptr = array;

    fill_array_elements(&array_ptr, &size);
    int major_element = find_biggest_element(array_ptr, &size);
    print_array_elements(array_ptr, &size, major_element);

    return 0;

}

int array_size_input(int *size) {

    printf("*** DATA INPUT ***\n\n");
    printf("Enter the size of the array: ");
    scanf("%d", size);

    while(*size <= 0) {
        printf("\n-> The size is invalid! Enter a new size again: ");
        scanf("%d", size);
    }

    return *size;

}

void fill_array_elements(int **array_ptr, int *size) {

    printf("\n*** FILL THE ELEMENTS OF THE ARRAY ***\n\n");

    printf("-> Fill in the elements' values of the array in the positions below:\n\n");

    for(int i = 0; i < *size; i++) {
        printf("array_ptr[%d]: ", i);
        scanf("%d", (*array_ptr + i));
    }

}

int find_biggest_element(int *array_ptr, int *size) {

    int major = *array_ptr;

    for(int i = 0; i < *size; i++) {
        if(major < *(array_ptr + i)) {
            major = *(array_ptr + i);
        }
    }

    return major;

}

void print_array_elements(int *array_ptr, int *size, int major_element) {

    printf("\n*** PRINT ARRAY ELEMENTS ***\n\n");
    for(int i = 0; i < *size; i++) {
        printf("array_ptr[%d]: %d\n", i, *(array_ptr + i));
    }

    putchar('\n');

    printf("-> The biggest element of the array is: %d.\n", major_element);

}