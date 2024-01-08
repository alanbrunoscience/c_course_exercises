#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions prototype
void file_name_input(char **file_name);
int validate_mem_alloc(char *file_name);
int count_lines_file(char *file_name);
void search_vowels_file(char *file_name);

int main() {

    char *file_name;

    file_name_input(&file_name);
    search_vowels_file(file_name);

    free(file_name);

    return 0;

}

void file_name_input(char **file_name) {

    // Allocate memory dynamically for "file_name" variable
    *file_name = (char *)malloc(100 * sizeof(char));

    if(validate_mem_alloc(*file_name)) {
        exit(1);
    }

    printf("*** DATA INPUT ***\n\n");
    printf("Enter the file name, please: ");
    scanf(" %[^\n]", *file_name);

    // Reallocate memory with the correct size of the string "file_name"
    *file_name = (char *)realloc(*file_name, (strlen(*file_name) + 1) * sizeof(char));

    if(validate_mem_alloc(*file_name)) {
        exit(1);
    }

}

int validate_mem_alloc(char *file_name) {

    if(file_name == NULL) {
        printf("\n-> Memory (re)allocation failed.\n");
        return 1;
    }

    return 0;

}

int count_lines_file(char *file_name) {

    FILE *fptr;
    char c;
    int count_lines = 0;

    fptr = fopen(file_name, "r");

    if(fptr == NULL) {
        puts("\n-> Unable to open the file.");
        exit(1);
    }

    while((c = getc(fptr)) != EOF) {
        if(c == '\n') {
            count_lines++;
        }
    }

    // Check if the last line doesn't end with a newline character
    if (count_lines > 0) {
        fseek(fptr, -1, SEEK_END); // Move one character before the end of the file
        if (fgetc(fptr) != '\n') {
            count_lines++;
        }
    }

    fclose(fptr);

    return count_lines;

}

void search_vowels_file(char *file_name) {

    FILE *fptr;
    char c;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'}, size = sizeof(vowels) / sizeof(vowels[0]);
    int count_vowels = 0;
    int count_lines = count_lines_file(file_name);

    fptr = fopen(file_name, "r");

    if(fptr == NULL) {
        puts("\n-> Unable to open the file.");
        exit(1);
    }

    printf("\n*** VOWELS IN THE FILE ***\n\n");
    printf("Vowels:\n\n");

    for(int i = 1; i <= count_lines; i++) {
        printf("-> %dº line: ", i);
        if(i != count_lines) {
            while((c = fgetc(fptr)) != '\n') {
                for(int j = 0; j < size; j++) {
                    if(c == vowels[j]) {
                        printf("%c ", c);
                        count_vowels++;
                    }
                }
            }
        } else {
            
            while((c = fgetc(fptr)) != EOF) {
                for(int j = 0; j < size; j++) {
                    if(c == vowels[j]) {
                        printf("%c ", c);
                        count_vowels++;
                    }
                }
            }

        }

        printf("\n");

    }

    printf("\n-> Quantity of vowels: %d\n", count_vowels);

    fclose(fptr);

}