#include <stdio.h>

int main() {

    FILE *fptr;
    char fruit[20];

    fptr = fopen("fruits.txt", "a");

    if(fptr) {
        
        puts("Enter a fruit, or press 0 to exit:");
        fgets(fruit, 20, stdin);
        while(fruit[0] != '0') {
            fputs(fruit, fptr);
            puts("\nEnter a fruit, or press 0 to exit:");
            fgets(fruit, 20, stdin);
        }

        fclose(fptr);

    } else {
        puts("It was not possible to open the file.");
    }

    return 0;    

}