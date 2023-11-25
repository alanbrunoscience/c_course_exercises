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

    return 0;

}

void changeValues(int *a, int *b) {
    if(*a < *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

void printValues(int *a, int *b) {

    printf("\n*** DATA OUTPUT *** \n\n");
    printf("*PS.: The highest value was placed in the first variable entered, and the lowest value in the second.\n\n");
    printf("-> A = %d;\n", *a);
    printf("-> B = %d.\n", *b);
    
}
