#include <stdio.h>
#include <stdlib.h>

// Functions prototype
void data_input(int **array_num, int *size);
int memory_alloc_validation(int *array_num);
void biggest_element(int *array_num, int *size);

int main() {

    int *array_num, *size;

    // Allocate memory dynamically for the variable 'size'
    size = (int *)calloc(1, sizeof(int));

    // Validating memory allocation
    if(size == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    data_input(&array_num, size);

    biggest_element(array_num, size);

    free(array_num);
    free(size);

    return 0;

}

void data_input(int **array_num, int *size) {

    printf("*** DATA INPUT ***\n\n");
    printf("-> Enter the total quantity of the elements of the array: ");
    scanf("%d", size);

    // Dynamic memory allocation for the array
    *array_num = (int *)malloc(*size * sizeof(int));

    if (memory_alloc_validation(*array_num)) {
        exit(1);
    }

    // Input of the elements' values of the array
    printf("\n*** FILL THE ELEMENTS OF THE ARRAY ***\n\n");
    printf("-> Fill in the elements' values of the array in the positions below:\n\n");
    int i = 0;
    while (i < *size) {
        printf("array_num[%d]: ", i);
        scanf("%d", (*array_num + i));
        i++;
    }

}

int memory_alloc_validation(int *array_num) {
    if(array_num == NULL) {
        printf("Memory (re)allocation failed.\n");
        return 1;
    }
    return 0;
}

void biggest_element(int *array_num, int *size) {

    int major = *array_num, countMajor = 0;

    for(int i = 0; i < *size; i++) {
        if(major < *(array_num + i)) {
            major = *(array_num + i);
        }
    }

    for(int i = 0; i < *size; i++) {
        if(major == *(array_num + i)) {
            countMajor++;
        }
    }

    printf("\nThe largest element is %d, and this value was repeated %d times in the array.\n", major, countMajor);

}
