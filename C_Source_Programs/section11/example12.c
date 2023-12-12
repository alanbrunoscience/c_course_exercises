#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fptr;
    char title[50];
    int reg_num;
    double price;

    fptr = fopen("books.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (fscanf(fptr, "Title: %49[^|] | Reg. Number: %d | Price: %lf", title, &reg_num, &price) != EOF) { // It reads formatted data.
        
        // Skip the rest of the line
        while (fgetc(fptr) != '\n');
        
        printf("Title: %s| Reg. Number: %d | Price: %.2lf\n", title, reg_num, price);
        
    }

    fclose(fptr);

    return 0;

}