#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

typedef struct BinariesNumbers {

    int dec_num;
    int *binary_number;
    int binary_size;

} BinariesNumbers;

// Functions prototype
void filename_input(char **filename);
void allocate_memory(char **filename);
void reallocate_memory(char **filename);
int validate_mem_alloc(char *filename);
void decimal_numbers_input(int *quantity_num, BinariesNumbers numbers[]);
void conversion_to_binary(int *quantity_num, BinariesNumbers numbers[]);
void write_binaries_file(char *filename, int *quantity_num, BinariesNumbers numbers[]);
void print_content_file(char *filename);

int main() {

    char *filename;
    int quantity_num = 10;
    BinariesNumbers numbers[quantity_num];

    filename_input(&filename);
    decimal_numbers_input(&quantity_num, numbers);
    conversion_to_binary(&quantity_num, numbers);
    write_binaries_file(filename, &quantity_num, numbers);
    print_content_file(filename);

    free(filename);

    return 0;

}

void filename_input(char **filename) {

    allocate_memory(filename);

    printf("*** FILENAME INPUT ***\n\n");
    printf("Enter the name of the file to be written: ");
    scanf(" %[^\n]", *filename);

    reallocate_memory(filename);

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

void decimal_numbers_input(int *quantity_num, BinariesNumbers numbers[]) {

    printf("\n*** DECIMAL NUMBERS INPUT ***\n\n");
    printf("Fill in the elements' values in the positions below:\n\n");
    for(int i = 0; i < *quantity_num; i++) {
        printf("numbers[%d]: ", i);
        scanf("%d", &numbers[i].dec_num);
    }

}

void conversion_to_binary(int *quantity_num, BinariesNumbers numbers[]) {

    for(int i = 0; i < *quantity_num; i++) {

        int original_value = numbers[i].dec_num;
        int length = 0;
        int remainder = 0;
        numbers[i].binary_number = NULL;

        for(int j = original_value; j > 0; j /= 2) {
            length++;
        }

        int *temp = (int *)realloc(numbers[i].binary_number, length * sizeof(int));

        if(temp == NULL) {
            puts("\n-> Memory (re)allocation failed.");
            free(numbers[i].binary_number);
            exit(1);
        }

        numbers[i].binary_number = temp;
        numbers[i].binary_size = length;

        for(int k = (length - 1); k >= 0; k--) {
            remainder = original_value % 2;
            numbers[i].binary_number[k] = remainder;
            original_value /= 2;
        }

    }

}

void write_binaries_file(char *filename, int *quantity_num, BinariesNumbers numbers[]) {

    FILE *fptr;

    if((fptr = fopen(filename, "w")) == NULL) {
        puts("\n-> Unable to open the file.");
        exit(1);
    }

    fputs("*** DECIMAL TO BINARY CONVERTER ***\n\n", fptr);
    for(int i = 0; i < *quantity_num; i++) {
        
        fprintf(fptr, "%dº) %d (decimal) = ", i+1, numbers[i].dec_num);

        for(int j = 0; j < numbers[i].binary_size; j++) {
            fprintf(fptr, "%d ", numbers[i].binary_number[j]);
        }

        fputs("(binary)\n", fptr);

        free(numbers[i].binary_number);

    }

    fclose(fptr);

}

void print_content_file(char *filename) {

    FILE *fptr;
    char *str = NULL;
    size_t len = 0;

    if ((fptr = fopen(filename, "r")) == NULL) {
        puts("\n-> Unable to open the file for reading.");
        exit(1);
    }

    printf("\n\n*** PRINT GENERATED FILE CONTENT ***\n\n");
    while (getline(&str, &len, fptr) != -1) {
        printf("%s", str);
    }

    printf("\n");

    free(str);

    fclose(fptr);

}