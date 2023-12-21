#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50

// Functions prototype
void file_names_input(char **file_name1, char **file_name2);
void allocate_memory(char **file_name1, char **file_name2);
int validate_mem_alloc(char *file_name);
void reallocate_memory(char **file_name);
void create_new_file(char *file_name1, char *file_name2);
void print_old_file_content(char *file_name1);
void print_new_file_content(char *file_name2);

int main() {

    char *file_name1, *file_name2;

    file_names_input(&file_name1, &file_name2);
    create_new_file(file_name1, file_name2);
    print_old_file_content(file_name1);
    print_new_file_content(file_name2);

    free(file_name1);
    free(file_name2);

    return 0;

}

void allocate_memory(char **file_name1, char **file_name2) {

    // Allocate and validate memory dynamically for the "file_name1" and "file_name2" pointers
    *file_name1 = (char *)malloc(MAX_FILE_NAME_LENGTH * sizeof(char));

    if(validate_mem_alloc(*file_name1)) {
        exit(1);
    }

    *file_name2 = (char *)malloc(MAX_FILE_NAME_LENGTH * sizeof(char));

    if(validate_mem_alloc(*file_name2)) {
        exit(1);
    }

}

int validate_mem_alloc(char *file_name) {
    if(file_name == NULL) {
        puts("\n-> Memory (re)allocation failed.");
        return 1;
    }
    return 0;
}

void reallocate_memory(char **file_name) {

    // Reallocating memory dynamically for the correct size of the "file_name" pointer
    *file_name = (char *)realloc(*file_name, (strlen(*file_name) + 1) * sizeof(char));

    if(validate_mem_alloc(*file_name)) {
        exit(1);
    }

}

void file_names_input(char **file_name1, char **file_name2) {

    allocate_memory(file_name1, file_name2);

    printf("*** DATA INPUT ***\n\n");
    printf("1) Enter the name of the file to be read: ");
    scanf(" %[^\n]", *file_name1);

    reallocate_memory(file_name1);

    printf("\n2) Enter the name of the file to be write: ");
    scanf(" %[^\n]", *file_name2);

    while(strcmp(*file_name1, *file_name2) == 0) {
        printf("\n-> The name of the second file is the same as the first. So, the content of the second will overwrite the first. Enter a different name for the second file, please: ");
        scanf(" %[^\n]", *file_name2);
    }

    reallocate_memory(file_name2);

}

void create_new_file(char *file_name1, char *file_name2) {

    FILE *fptr1, *fptr2;
    char ch;

    if((fptr1 = fopen(file_name1, "r")) == NULL) {
        puts("\n-> It was not possible to open the file.");
        exit(1);
    }

    if((fptr2 = fopen(file_name2, "w")) == NULL) {
        puts("\n-> It was not possible to open the file.");
        exit(1);
    } else {
        while((ch = fgetc(fptr1)) != EOF) {
            if(ch != 13 && ch != 10) {
                fprintf(fptr2, "%c", (ch - 32));
            } else {
                if(ch == 13) {
                    fprintf(fptr2, "%c", '\r');
                }
                if(ch == 10) {
                    fprintf(fptr2, "%c", '\n');
                }
                
            }
        } 
    }

    fclose(fptr1);
    fclose(fptr2);

}

void print_old_file_content(char *file_name1) {

    FILE *fptr1;
    char ch;

    fptr1 = fopen(file_name1, "r");

    if (fptr1 == NULL) {
        puts("\n-> It was not possible to open the file for reading.");
        exit(1);
    }

    printf("\n*** OLD FILE CONTENT ***\n\n");
    while ((ch = fgetc(fptr1)) != EOF) {
        printf("%c", ch);
    }

    printf("\n");

    fclose(fptr1);

}

void print_new_file_content(char *file_name2) {

    FILE *fptr2;
    char ch;

    fptr2 = fopen(file_name2, "r");

    if (fptr2 == NULL) {
        puts("\n-> It was not possible to open the file for reading.");
        exit(1);
    }

    printf("\n*** NEW FILE CONTENT ***\n\n");
    while ((ch = fgetc(fptr2)) != EOF) {
        printf("%c", ch);
    }

    printf("\n");

    fclose(fptr2);

}

