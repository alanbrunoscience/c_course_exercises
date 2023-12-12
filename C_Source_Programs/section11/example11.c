// Writing to file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *fptr;
    int option = 1;
    char title[30];
    int reg_num;
    double price;

    fptr = fopen("books.txt", "a");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while(option == 1) {

        printf("******** OPTIONS ********\n\n");
        printf("-> Choose an option below:\n\n");
        printf("1) Register books;\n");
        printf("2) Exit the program.\n\n-> ");
        scanf("%d", &option);

        switch(option) {

            case 1:

                printf("\nEnter the title, registration number, and price of the book:\n-> ");
                scanf(" %[^\n]", title);
                printf("-> ");
                scanf("%d", &reg_num);
                printf("-> ");
                scanf("%lf", &price);

                fprintf(fptr, "Title: %s | Reg. Number: %d | Price: %.2lf\n", title, reg_num, price); // It writes formatted data.

                printf("\n");

                break;

            case 2:

                printf("\nFinishing the program...\n");

                break;

            default:

                printf("\nInvalid option!\n");

        }

    }

    fclose(fptr);

    return 0;
}
