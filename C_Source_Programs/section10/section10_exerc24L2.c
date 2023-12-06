#include <stdio.h>

// Functions prototype
int array_size_input(int *size);
void fill_array_elements(int **array_ptr, int *size);
void find_max_min_elements(int *array_ptr, int *size, int *max, int *min);
void print_max_min_elements(int *max, int *min);

int main() {

    int size, max, min;

    array_size_input(&size);

    int array[size];
    int *array_ptr = array;

    fill_array_elements(&array_ptr, &size);
    find_max_min_elements(array_ptr, &size, &max, &min);
    print_max_min_elements(&max, &min);

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

void find_max_min_elements(int *array_ptr, int *size, int *max, int *min) {

    *max = *min = *array_ptr;

    for(int i = 0; i < *size; i++) {
        if(*max < *(array_ptr + i)) {
            *max = *(array_ptr + i);
        }

        if(*min > *(array_ptr + i)) {
            *min = *(array_ptr + i);
        }
    }
    
}

void print_max_min_elements(int *max, int *min) {

    printf("\n*** RESULTS ***\n\n");
    printf("-> The highest value element: %d / Address: %p;\n", *max, &max);
    printf("-> The lowest value element: %d / Address: %p.\n", *min, &min);

}