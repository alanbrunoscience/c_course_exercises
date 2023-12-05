#include <stdio.h>
#include <stdlib.h>

// Functions prototype
void data_input(float **array_num, int *size);
int memory_alloc_validation(float *array_num);
int negatives(float *array_num, int *size);
void print_negative_values(int total_neg);

int main() {

    float *array_num;
    int *size;

    // Allocate memory dynamically for the variable 'size'
    size = (int *)calloc(1, sizeof(int));

    // Validate memory allocation
    if(size == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    data_input(&array_num, size);
    int total_neg = negatives(array_num, size);
    print_negative_values(total_neg);

    free(array_num);
    free(size);

    return 0;

}

void data_input(float **array_num, int *size) {

    printf("*** DATA INPUT ***\n\n");
    printf("-> Enter the total quantity of the elements of the array: ");
    scanf("%d", size);

    // Dynamic memory allocation for the array
    *array_num = (float *)malloc(*size * sizeof(float));

    // Validate memory allocation
    if(memory_alloc_validation(*array_num)) {
        exit(1);
    }
    
    // Input of the elements' values of the array
    printf("\n*** FILL THE ELEMENTS OF THE ARRAY ***\n\n");
    printf("-> Fill in the elements' values of the array in the positions below:\n\n");
    int i = 0;
    while (i < *size) {
        printf("array_num[%d]: ", i);
        scanf("%f", (*array_num + i));
        i++;
    }

}

int memory_alloc_validation(float *array_num) {
    if(array_num == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }
    return 0;
}

int negatives(float *array_num, int *size) {

    int count_neg = 0;

    for(int i = 0; i < *size; i++) {
        if(*(array_num + i) < 0) {
            count_neg++;
        }
    }

    return count_neg;

}

void print_negative_values(int total_neg) {
    
    printf("\n*** TOTAL NEGATIVE NUMBERS ***\n\n");
    printf("-> Total negative numbers: %d.\n", total_neg);

}