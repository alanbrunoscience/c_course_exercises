#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fptr;

    fptr = fopen("test_str.txt", "w");

    if(fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    } 
    
    fputs("Ainda que eu falasse\n", fptr); // It writes line by line to the file.
    fputs("A língua dos homens\n", fptr);
    fputs("E falasse a língua dos anjos\n", fptr);
    fputs("Sem amor eu nada seria\n", fptr);

    printf("Yeah! The file was written.\n");

    fclose(fptr);

    return 0;

}