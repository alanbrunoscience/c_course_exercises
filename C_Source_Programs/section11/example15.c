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

    fptr = fopen("books.dat", "rb");

    if(fptr == NULL) {
        exit(1);
    }

    while(fread(&book, sizeof(Book), 1, fptr) == 1)
        print_book(book);
    
    fclose(fptr);

    return 0;

}

void print_book(Book book) {

    printf("\nTitle: %s", book.title);
    printf("Author: %s", book.author);
    printf("Reg. Number: %hd\n", book.reg_number);
    printf("Price: %.2lf\n", book.price);

}
