#include <stdio.h>

// Functions prototype
void grades_input(float *n1, float *n2);
int validate_grades(float *grade);
void calc_averages(float *simple_average, float *weighted_average, float *n1, float *n2);
void print_results(float *simple_average, float *weighted_average);

int main() {

    float n1, n2, simple_average, weighted_average;

    grades_input(&n1, &n2);
    calc_averages(&simple_average, &weighted_average, &n1, &n2);
    print_results(&simple_average, &weighted_average);

    return 0;

}

void grades_input(float *n1, float *n2) {

    int function_ret;

    printf("*** INPUT OF GRADES ***\n\n");
    
    printf("Enter the first grade, please: ");
    scanf("%f", n1);

    while(!(function_ret = validate_grades(n1))) {
        validate_grades(n1);
    }

    putchar('\n');

    printf("Enter the second grade, please: ");
    scanf("%f", n2);

    while(!(function_ret = validate_grades(n2))) {
        validate_grades(n2);
    }

}

int validate_grades(float *grade) {

    if(*grade < 0 || *grade > 10) {
        printf("\n-> The grade informed is not valid. It needs to be between 0 and 10 (including). Enter the grade again: ");
        scanf("%f", grade);
        return 0;
    } else {
        return 1;
    }

}

void calc_averages(float *simple_average, float *weighted_average, float *n1, float *n2) {

    *simple_average = (*n1 + *n2) / 2;
    *weighted_average = (*n1 + *n2 * 2) / 3;

}

void print_results(float *simple_average, float *weighted_average) {

    printf("\n*** RESULTS ***\n\n");
    printf("-> Simple Average: %.2f;\n", *simple_average);
    printf("-> Weighted Average: %.2f.\n", *weighted_average);

}