#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50

// Functions prototype
void file_name_input(char **file_name);
int validate_mem_alloc(char *file_name);
void create_new_file(char *file_name);

int main() {

    char *file_name;

    file_name_input(&file_name);
    create_new_file(file_name);

    free(file_name);

    return 0;

}

void file_name_input(char **file_name) {

    // Allocate memory dynamically for the "file_name" pointer
    *file_name = (char *)malloc(MAX_FILE_NAME_LENGTH * sizeof(char));

    if(validate_mem_alloc(*file_name)) {
        exit(1);
    }

    printf("*** DATA INPUT ***\n\n");
    printf("Enter the name of the file: ");
    scanf(" %[^\n]", *file_name);

    // Reallocating memory dynamically with the correct size of the "file_name" pointer
    *file_name = (char *)realloc(*file_name, (strlen(*file_name) + 1) * sizeof(char));

    if(validate_mem_alloc(*file_name)) {
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

void create_new_file(char *file_name) {

    FILE *fptr, *fptr2;
    char ch, vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int size = sizeof(vowels) / sizeof(vowels[0]), is_vowel;

    fptr = fopen(file_name, "r");

    if(fptr == NULL) {
        puts("\n-> It was not possible to open the file.");
        exit(1);
    }

    fptr2 = fopen("file2.txt", "w");

    if(fptr2 == NULL) {
        puts("\n-> It was not possible to create the file.");
        exit(1);
    } else {
        while((ch = fgetc(fptr)) != EOF) {

            is_vowel = 0;

            for(int i = 0; i < size; i++) {
                if(ch == vowels[i]) {
                    is_vowel++;
                }
            }

            if(is_vowel) {
                fprintf(fptr2, "%c", '*');
            } else {
                fprintf(fptr2, "%c", ch);
            }
            
        }
    }

    fclose(fptr);

    // Close the file before reopening for reading
    fclose(fptr2);

    fptr2 = fopen("file2.txt", "r"); // Open in read mode this time

    if (fptr2 == NULL) {
        puts("\n-> It was not possible to open the file for reading.");
        exit(1);
    }

    // Print new file
    printf("\n*** NEW FILE CONTENT ***\n\n");
    while ((ch = fgetc(fptr2)) != EOF) {
        printf("%c", ch);
    }

    printf("\n");

    fclose(fptr2);

}