#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fptr;
    char c;

    fptr = fopen("file.txt", "r");

    if(fptr) {
        while((c = getc(fptr)) != EOF) {
            printf("%c", c);
        }
        fclose(fptr);
    } else {
        puts("File not found.");
    } 

    return 0;

}