#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions prototype
void file_name_input(char **file_name);
int test_mem_alloc(char *file_name);
void count_lines_file(char *file_name);

int main() {

    char *file_name;

    file_name_input(&file_name);
    count_lines_file(file_name);

    // Free the allocated memory
    free(file_name);

    return 0;

}

void file_name_input(char **file_name) {

    // Use malloc to dynamically allocate memory for the string
    *file_name = (char *)malloc(100 * sizeof(char));

    if(test_mem_alloc(*file_name)) {
        exit(1);
    }

    printf("***** DATA INPUT *****\n\n");
    printf("Enter the name of the file: ");
    scanf(" %[^\n]", *file_name);

    // Reallocate memory with the correct size of the string "file_name"
    *file_name = (char *)realloc(*file_name, (strlen(*file_name) + 1) * sizeof(char));

    if(test_mem_alloc(*file_name)) {
        exit(1);
    }
    
}

int test_mem_alloc(char *file_name) {
    if(file_name == NULL) {
        printf("\n-> Memory (re)allocation failed.\n");
        return 1;
    }
    return 0;
}

void count_lines_file(char *file_name) {

    FILE *fptr;
    char c;
    int count_lines = 0;
    
    fptr = fopen(file_name, "r");

    if(fptr == NULL) {
        printf("\n-> It was not possible to open the file.\n");
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
        if (getc(fptr) != '\n') {
            count_lines++;
        }
    }

    printf("\n-> The number of lines of the %s is: %d.\n", file_name, count_lines);

    fclose(fptr);

}