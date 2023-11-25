#include <stdio.h>

// Functions prototype
int sumOfDouble(int *a, int *b);
void printResults(int *a, int *b, int sumDouble);

int main() {

    int a, b;

    printf("Enter the first value, please:\n");
    scanf("%d", &a);

    printf("Enter the second value, please:\n");
    scanf("%d", &b);

    int sumDouble = sumOfDouble(&a, &b);

    printResults(&a, &b, sumDouble);

    return 0;
    
}

int sumOfDouble(int *a, int *b) {
    
    int sum;

    *a = *a * 2;
    *b = *b * 2;

    sum = *a + *b;

    return sum;

}

void printResults(int *a, int *b, int sumDouble) {
    printf("(%d * 2) + (%d * 2) = %d.\n", *a / 2, *b / 2, sumDouble);
}