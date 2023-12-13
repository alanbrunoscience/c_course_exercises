#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fptr;

    fptr = fopen("file.txt", "w");

    if(fptr == NULL) {
        puts("It was not possible to open the file.");
        exit(1);
    }

    fclose(fptr);

    return 0;

}