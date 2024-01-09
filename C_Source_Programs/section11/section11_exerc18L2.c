/* FILE CONTENT 

Name: Powerade Ultra | Price: $ 1.89
Name: Microban 24 Hour Sanitizing Spray | Price: $ 17.49
Name: All Free Clear Pure | Price: $ 24.05
Name: Snuggle SuperCare Scent Booster | Price: $ 7.97
Name: Downy Intense Scent + Freshness, Spring Rush Scent | Price: $ 12.19
Name: Purina Pro Plan LiveClear Cat Food | Price: $ 21.58

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

// Functions prototype
void filename_input(char **filename);
int validate_file_existence(char *filename);
void allocate_memory(char **filename);
void reallocate_memory(char **filename);
int validate_mem_alloc(char *filename);
void print_content_file(char *filename);
void calculate_products_price(char *filename);

int main() {

    char *filename;

    filename_input(&filename);
    print_content_file(filename);
    calculate_products_price(filename);

    free(filename);

    return 0;

}

void filename_input(char **filename) {

    allocate_memory(filename);

    printf("*** FILENAME INPUT ***\n\n");
    printf("Enter the name of the file to be read: ");
    scanf(" %[^\n]", *filename);

    while(validate_file_existence(*filename)) {
        printf("\n-> Unable to open the file. Make sure that this file exists or that the filename is correct. Enter the filename again: ");
        scanf(" %[^\n]", *filename);
    }

    reallocate_memory(filename);

}

int validate_file_existence(char *filename) {

    FILE *fptr;

    if((fptr = fopen(filename, "r")) == NULL) {
        return 1;
    }

    fclose(fptr);

    return 0;

}

void allocate_memory(char **filename) {

    *filename = (char *)malloc(MAX_FILENAME_LENGTH * sizeof(char));

    if(validate_mem_alloc(*filename)) {
        exit(1);
    }

}

void reallocate_memory(char **filename) {

    *filename = (char *)realloc(*filename, (strlen(*filename) + 1) * sizeof(char));

    if(validate_mem_alloc(*filename)) {
        exit(1);
    }

}

int validate_mem_alloc(char *filename) {
    
    if(filename == NULL) {
        puts("\n-> Memory (re)allocation failed.");
        return 1;
    }

    return 0;

}

void print_content_file(char *filename) {

    FILE *fptr;
    char *str = NULL;
    size_t len = 0;

    fptr = fopen(filename, "r");

    printf("\n*** PRODUCTS' LIST INFO ***\n\n");
    while (getline(&str, &len, fptr) != -1) {
        printf("%s", str);
    }

    printf("\n");

    free(str);

    fclose(fptr);

}

void calculate_products_price(char *filename) {

    FILE *fptr;
    char prod_name[100];
    float price;
    float total_price = 0.0;

    fptr = fopen(filename, "r");

    while(fscanf(fptr, "Name: %99[^|] | Price: $ %f\n", prod_name, &price) == 2) {
        total_price += price;
    }

    fclose(fptr);

    printf("\n-> Total Price: $ %.2f.\n", total_price);

}
