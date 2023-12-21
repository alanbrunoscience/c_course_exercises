#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50

// Functions prototype
void file_names_input(char **file_name1, char **file_name2, char **file_name3);
void allocate_memory(char **file_name);
int validate_mem_alloc(char *file_name);
void reallocate_memory(char **file_name);
void create_new_file(char *file_name1, char *file_name2, char *file_name3);
void print_file_content(char *file_name);

int main() {

    char *file_name1, *file_name2, *file_name3;

    file_names_input(&file_name1, &file_name2, &file_name3);
    create_new_file(file_name1, file_name2, file_name3);

    printf("\n*** FIRST FILE CONTENT ***\n\n");
    print_file_content(file_name1);

    printf("\n*** SECOND FILE CONTENT ***\n\n");
    print_file_content(file_name2);

    printf("\n*** EDITED FILE CONTENT ***\n\n");
    print_file_content(file_name3);

    free(file_name1);
    free(file_name2);
    free(file_name3);

    return 0;

}

void file_names_input(char **file_name1, char **file_name2, char **file_name3) {

    // Allocate memory dynamically for the pointers "file_name1", "file_name2", and "file_name3"
    allocate_memory(file_name1);
    allocate_memory(file_name2);
    allocate_memory(file_name3);

    printf("*** DATA INPUT ***\n\n");
    printf("1) Enter the name of the first file to be read: ");
    scanf(" %[^\n]", *file_name1);

    reallocate_memory(file_name1);

    printf("\n2) Enter the name of the second file to be read: ");
    scanf(" %[^\n]", *file_name2);

    while(strcmp(*file_name1, *file_name2) == 0) {
        printf("\n-> The name of the second file is the same as the first. Enter a different name for the second file, please: ");
        scanf(" %[^\n]", *file_name2);
    }

    reallocate_memory(file_name2);

    printf("\n3) Enter the name of the file to be write: ");
    scanf(" %[^\n]", *file_name3);

    while(strcmp(*file_name1, *file_name3) == 0 || strcmp(*file_name2, *file_name3) == 0) {
        printf("\n-> The name of the third file is the same as the files provided previously. So, the content of the third will overwrite the first or second. Enter a different name for the third file, please: ");
        scanf(" %[^\n]", *file_name3);
    }

    reallocate_memory(file_name3);

}

void allocate_memory(char **file_name) {

    *file_name = (char *)malloc(MAX_FILE_NAME_LENGTH * sizeof(char));
    
    if(validate_mem_alloc(*file_name)) {
        exit(1);
    }
}

void reallocate_memory(char **file_name) {

    // Reallocate memory
    *file_name = (char *)realloc(*file_name, (strlen(*file_name) + 1) * sizeof(char));

    if (validate_mem_alloc(*file_name)) {
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

void create_new_file(char *file_name1, char *file_name2, char *file_name3) {
    
    FILE *fptr1, *fptr2, *fptr3;
    char *str = NULL;
    size_t len = 0;

    if((fptr1 = fopen(file_name1, "r")) == NULL) {
        puts("\n-> It was not possible to open the file.");
        exit(1);
    }

    if((fptr2 = fopen(file_name2, "r")) == NULL) {
        puts("\n-> It was not possible to open the file.");
        exit(1);
    }

    if((fptr3 = fopen(file_name3, "a")) == NULL) {
        puts("\n-> It was not possible to open the file.");
        exit(1);
    } else {
        while(getline(&str, &len, fptr1) != -1) {
            fputs(str, fptr3);
        }

        fseek(fptr1, -1, SEEK_END);
        if(fgetc(fptr1) != '\n') {
            fputc('\n', fptr3);
            while(getline(&str, &len, fptr2) != -1) {
                fputs(str, fptr3);
            }
        } else {
            while(getline(&str, &len, fptr2) != -1) {
                fputs(str, fptr3);
            }
        }

        fputc('\n', fptr3);
        
    }

    free(str);

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);

}

void print_file_content(char *file_name) {

    FILE *fptr;
    char *str = NULL;
    size_t len = 0;

    fptr = fopen(file_name, "r");

    if (fptr == NULL) {
        puts("\n-> It was not possible to open the file for reading.");
        exit(1);
    }

    while (getline(&str, &len, fptr) != -1) {
        printf("%s", str);
    }

    printf("\n");

    free(str);

    fclose(fptr);

}