#include <stdio.h>
#include <math.h>

// Functions prototype
void data_input(float *a, float *b, float *c);
float delta_calculation(float *a, float *b, float *c);
int roots_calculation(float *delta_result, float *a, float *b, float *x1, float *x2);
void print_roots(int *root_result, float *x1, float *x2);

int main() {

    float a, b, c, x1, x2;

    data_input(&a, &b, &c);
    
    float delta_result = delta_calculation(&a, &b, &c);

    int root_result = roots_calculation(&delta_result, &a, &b, &x1, &x2);

    print_roots(&root_result, &x1, &x2);

    return 0;

}

void data_input(float *a, float *b, float *c) {

    printf("*** SECOND DEGREE EQUATION ***\n\n");
    printf("Enter the coefficients below:\n\n");
    printf("-> A (x²): ");
    scanf("%f", a);
    printf("-> B (x): ");
    scanf("%f", b);
    printf("-> C: ");
    scanf("%f", c);

}

float delta_calculation(float *a, float *b, float *c) {

    float delta;

    delta = pow(*b, 2) - 4 * (*a) * (*c);

    return delta;

}

int roots_calculation(float *delta_result, float *a, float *b, float *x1, float *x2) {

    int number_roots;

    if(*delta_result < 0.0) {

        
        number_roots = 0;
        return number_roots;

    } else if(*delta_result == 0.0) {
        *x1 = (-(*b)) / (2 * (*a));
        number_roots = 1;
        return number_roots;
        
    } else {
        *x1 = (-(*b) + sqrt(*delta_result)) / (2 * (*a));
        *x2 = (-(*b) - sqrt(*delta_result)) / (2 * (*a));
        number_roots = 2;
        return number_roots;
        
    }

}

void print_roots(int *root_result, float *x1, float *x2) {
    
    if(*root_result == 0) {
        printf("\nThere is no real root for this equation.\n");
    } else if(*root_result == 1) {
        printf("\nThere is a single root for this equation and its result is %.2f.\n", *x1);
    } else {
        printf("\nThere are two roots for this equation and their results are:\n");
        printf("-> x1: %.2f;\n", *x1);
        printf("-> x2: %.2f.\n", *x2);
    }

}