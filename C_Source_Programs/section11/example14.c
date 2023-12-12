#include <stdio.h>
#include <stdlib.h>

typedef struct Book {
    char title[50];
    char author[50];
    short reg_number;
    double price;
} Book;

Book get_book();

int main() {

    Book book;
    int answer;
    FILE *fptr;

    fptr = fopen("books.dat", "wb");

    if(fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    do {

        book = get_book();

        if(fwrite(&book, sizeof(book), 1, fptr) != 1)
            break;
        
        printf("\nAnother book (y/n)? ");
        answer = getchar();

        // Clear the input buffer
        while (answer != '\n' && getchar() != '\n');

    } while(answer != 'n' && answer != 'N');

    fclose(fptr);

    return 0;

}

Book get_book() {

    Book book;

    printf("\nEnter the title: ");
    fgets(book.title, sizeof(book.title), stdin);
    printf("Enter the author's name: ");
    fgets(book.author, sizeof(book.author), stdin);
    printf("Enter the registration number: ");
    scanf("%hd", &book.reg_number);
    printf("Enter the price: ");
    scanf("%lf", &book.price);

    // Clear the input buffer
    while (getchar() != '\n');

    return book;

}