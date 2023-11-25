#include <stdio.h>

// Functions prototype
void changeValues(int *a, int *b);
void printValues(int *a, int *b);

int main() {

    int a, b;

    printf("Enter the first value, please:\n");
    scanf("%d", &a);

    printf("Enter the second value, please:\n");
    scanf("%d", &b);

    changeValues(&a, &b);

    printValues(&a, &b);

}

void changeValues(int *a, int *b) {

    int temp = *a;

    *a = *b;
    *b = temp;
}

void printValues(int *a, int *b) {
    printf("\n*** NEW VALUE OF VARIABLES ***\n\n");
    printf("-> A (1st entered value) = %d;\n", *a);
    printf("-> B (2nd entered value) = %d.\n", *b);
}