#include <stdio.h>
#include <stdlib.h>

// Functions prototype
float data_input(float *num);
void frac(float *num, int *int_part, float *frac_part);
void print_results(float *num, int *int_part, float *frac_part);

int main() {

    float *num, *frac_part;
    int *int_part;

    // Allocate memory dynamically for variables stipulated
    num = (float *)calloc(1, sizeof(float));
    frac_part = (float *)calloc(1, sizeof(float));
    int_part = (int *)calloc(1, sizeof(int));

    // Validating memory allocation
    if(num == NULL || frac_part == NULL || int_part == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    // Calling the functions
    data_input(num);
    frac(num, int_part, frac_part);
    print_results(num, int_part, frac_part);

    // Freeing allocated memory
    free(num);
    free(frac_part);
    free(int_part);

    return 0;

}

float data_input(float *num) {

    printf("Enter a real number, please: ");
    scanf("%f", num);

    return *num;

}

void frac(float *num, int *int_part, float *frac_part) {

    *int_part = (int)*num;
    *frac_part = *num - ((int)*num);

}

void print_results(float *num, int *int_part, float *frac_part) {

    printf("\n*** RESULTS ***\n\n");
    printf("-> Number Entered: %.2f;\n", *num);
    printf("-> Integer Part: %d;\n", *int_part);
    printf("-> Fractional Part: %.2f;\n", *frac_part);

}