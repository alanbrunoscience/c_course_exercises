#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fptr;
    char ch;

    fptr = fopen("test.txt", "r");

    if(fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while((ch = fgetc(fptr)) != EOF) { // It reads character by character in the file, up to EOF.
        printf("%c", ch);
    }

    fclose(fptr);

    printf("\n");

    return 0;

}