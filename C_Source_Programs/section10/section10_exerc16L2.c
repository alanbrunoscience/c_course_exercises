#include <stdio.h>
#include <stdlib.h>

int main() {

    int a, *b, **c, ***d;

    printf("Enter an integer value, please: ");
    scanf("%d", &a);

    b = &a;
    c = &b;
    d = &c;

    printf("\n*** RESULTS ***\n\n");
    printf("%d * 2 = %d;\n", *b, *b * 2);
    printf("%d * 3 = %d;\n", **c, **c * 3);
    printf("%d * 4 = %d.\n", ***d, ***d * 4);

    return 0;
}
