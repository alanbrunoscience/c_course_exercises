#include <stdio.h>
#include <stdlib.h>

void change_values(int *a, int *b, int *c, int index, int d[]);

int main() {

    int a, b, c, index = 5;
    int *d = malloc(index * sizeof(int));

    if(d == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }

    change_values(&a, &b, &c, index, d);

    printf("*** VARIABLES' VALUES ***\n\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);

    printf("\n*** PRINT ARRAY ***\n\n");
    for(int i = 0; i < index; i++) {
        printf("d[%d]: %d\n", (i+1), d[i]);
    }

    free(d);

    return 0;

}

void change_values(int *a, int *b, int *c, int index, int d[]) {

    *a = 1;
    *b = 2;
    *c = 3;

    int values[] = {31, 28, 31, 30, 31};

    for(int i = 0; i < index; i++) {
        d[i] = values[i];
    }

}