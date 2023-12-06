#include <stdio.h>
#include <math.h>

// Functions prototype
void data_input(float *a, float *b, float *c);
void roots_calculation(float *a, float *b, float *c, float *x1, float *x2);

int main() {

    float a, b, c, x1, x2;

    data_input(&a, &b, &c);
    roots_calculation(&a, &b, &c, &x1, &x2);

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

void roots_calculation(float *a, float *b, float *c, float *x1, float *x2) {

    float delta;

    delta = pow(*b, 2) - 4 * (*a) * (*c);

    if(delta < 0.0) {
        printf("\nThere is no real root for this equation.\n");
    } else if(delta == 0.0) {
        *x1 = (-(*b)) / (2 * (*a));
        printf("\nThere is a single root for this equation and its result is %.2f.\n", *x1);
    } else {
        *x1 = (-(*b) + sqrt(delta)) / (2 * (*a));
        *x2 = (-(*b) - sqrt(delta)) / (2 * (*a));
        printf("\nThere are two roots for this equation and their results are:\n");
        printf("-> x1: %.2f;\n", *x1);
        printf("-> x2: %.2f.\n", *x2);
    }

}