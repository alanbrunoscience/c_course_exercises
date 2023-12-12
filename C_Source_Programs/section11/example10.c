#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fptr;
    char str[81];

    fptr = fopen("test_str.txt", "r");

    if(fptr == NULL) {
        puts("It was not possible to open the file.");
        exit(1);
    }

    while(fgets(str, 80, fptr) != NULL) { // It reads line by line in the file.
        printf("%s", str);
    }

    printf("\n");

    fclose(fptr);

    return 0;

}