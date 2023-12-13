#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fptr;
    char name[100], *result;

    fptr = fopen("file.txt", "r");

    if(fptr) {
        while(!feof(fptr)) {
            result = fgets(name, 100, fptr);
            printf("Result: %p\n", (void*)result);
            if(result) {
                printf("%s\n", name);
            }
        }

        fclose(fptr);
    } else {
        puts("File not found.");
    }

    return 0;

}