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
    char answer;
    FILE *fptr;
    long nrec, rec, position;
    
    fptr = fopen("books.dat", "rb");

    if(fptr == NULL) {
        printf("It was not possible to open the file.\n");
        exit(1);
    }

    fseek(fptr, 0, 2);

    nrec = ftell(fptr) / sizeof(book);

    printf("The number of register is %d");

}

void print_book(Book book) {

    printf("\nTitle: %s", book.title);
    printf("Author: %s", book.author);
    printf("Reg. Number: %hd\n", book.reg_number);
    printf("Price: %.2lf\n", book.price);

}
