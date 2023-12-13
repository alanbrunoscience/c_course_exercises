#include <stdio.h>
#include <stdlib.h>

typedef struct Book {
    char title[50];
    char author[50];
    short reg_number;
    double price;
} Book;

void print_book(Book book);

int main() {
    Book book;
    FILE *fptr;
    long nrec, rec, position;

    fptr = fopen("books.dat", "rb");

    if (fptr == NULL) {
        printf("It was not possible to open the file.\n");
        exit(1);
    }

    fseek(fptr, 0, SEEK_END); // Move to the end of the file to determine the number of records.

    nrec = ftell(fptr) / sizeof(book); // Calculate the number of records.

    printf("The number of registers is %ld.\n", nrec);

    puts("\nEnter the number of the register:");
    scanf("%ld", &rec);

    if (rec > 0 && rec <= nrec) {
        position = (rec - 1) * sizeof(Book); // Correct the calculation of the position.
        fseek(fptr, position, SEEK_SET); // Move to the correct position.
        fread(&book, sizeof(Book), 1, fptr);
        print_book(book);
        fclose(fptr);
    } else {
        puts("\nRegister doesn't exist!");
    }

    return 0;
}

void print_book(Book book) {
    printf("\nTitle: %s", book.title);
    printf("Author: %s", book.author);
    printf("Reg. Number: %hd\n", book.reg_number);
    printf("Price: %.2lf\n", book.price);
}
