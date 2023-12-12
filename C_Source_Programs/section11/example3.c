#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fptr;
    short int ch;

    fptr = fopen("test.txt", "r");

    if(fptr == NULL) {
        puts("It was not possible to open the file.");
        exit(1);
    }

    while((ch = fgetc(fptr)) != EOF) {
        printf("%c", ch);
    }

    printf("\n");

    fclose(fptr);

    return 0;

}