#include <stdio.h>

// Functions prototype
void sumAB(int *a, int *b);

int main() {

    int a = 4, b = 6;

    printf("*** INITIAL VALUES ***\n\n");
    printf("-> A = %d;\n", a);
    printf("-> B = %d.\n", b);

    sumAB(&a, &b);

    printf("\n*** VALUES MODIFIED ***\n\n");
    printf("-> A = %d (%d + %d);\n", a, (a - b), b);
    printf("-> B = %d.\n", b);

    return 0;

}

void sumAB(int *a, int *b) {
    *a = *a + *b;
}