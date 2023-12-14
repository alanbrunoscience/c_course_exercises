#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void data_input(char **file_name, char **c);
int test_mem_alloc(char *str);
void count_chars_file(char *file_name, char *c);

int main() {

    char *file_name, *c;

    data_input(&file_name, &c);
    count_chars_file(file_name, c);

    free(file_name);
    free(c);

    return 0;

}

void data_input(char **file_name, char **c) {

    // Allocate memory for 'file_name' and 'c' variables
    *file_name = (char *)malloc(100 * sizeof(char));

    if(test_mem_alloc(*file_name)) {
        exit(1);
    }

    *c = (char *)malloc(1 * sizeof(char));

    if(test_mem_alloc(*c)) {
        exit(1);
    }

    printf("*** DATA INPUT ***\n\n");
    printf("1) Enter the name of the file, please: ");
    scanf(" %[^\n]", *file_name);

    // Reallocate memory with the correct size of the string "file_name"
    *file_name = (char *)realloc(*file_name, (strlen(*file_name) + 1) * sizeof(char));

    if(test_mem_alloc(*file_name)) {
        exit(1);
    }

    printf("2) Enter a character to be searched into the file: ");
    scanf(" %c", *c);

}

int test_mem_alloc(char *str) {

    if(str == NULL) {
        printf("\n-> Memory (re)allocation failed.\n");
        return 1;
    }

    return 0;

}

void count_chars_file(char *file_name, char *c) {

    FILE *fptr;
    char c2;
    int count_chars = 0;

    fptr = fopen(file_name, "r");

    if(fptr == NULL) {
        puts("\n-> It was not possible to open the file.");
        exit(1);
    }

    while((c2 = fgetc(fptr)) != EOF) {
        if(c2 == *c) {
            count_chars++;
        }
    }

    if(count_chars > 0) {
        printf("\n-> The '%c' is repeated %d time(s) in the '%s'.\n", *c, count_chars, file_name);
    } else {
        printf("\n-> The '%c' is not repeated at any time in the '%s'.\n", *c, file_name);
    }

    fclose(fptr);

}
