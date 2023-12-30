#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50

// Functions prototype
void file_name_input(char **file_name);
int validate_file_existence(char *file_name);
void allocate_memory(char **file_name);
void reallocate_memory(char **file_name);
int validate_mem_alloc(char *file_name);
int count_number_characters(char *file_name);
int count_lines_file(char *file_name);
int count_words_file(char *file_name);
void data_output(char *file_name);
void count_chars_repetitions(char *file_name);

int main() {

    char *file_name;

    file_name_input(&file_name);
    data_output(file_name);
    count_chars_repetitions(file_name);

    free(file_name);

    return 0;

}

void file_name_input(char **file_name) {

    allocate_memory(file_name);

    printf("*** DATA INPUT ***\n\n");
    printf("1) Enter the name of the file to be read, please: ");
    scanf(" %[^\n]", *file_name);

    while(validate_file_existence(*file_name)) {
        printf("\n-> Unable to open the file. Make sure this file exists or its name is correct. Enter the file name again: ");
        scanf(" %[^\n]", *file_name);
    }

    reallocate_memory(file_name);

}

int validate_file_existence(char *file_name) {

    FILE *fptr;

    fptr = fopen(file_name, "r");

    if(fptr == NULL) {
        return 1;
    }

    fclose(fptr);

    return 0;

}

void allocate_memory(char **file_name) {

    *file_name = (char *)malloc(MAX_FILE_NAME_LENGTH * sizeof(char));

    if(validate_mem_alloc(*file_name)) {
        exit(1);
    }

}

void reallocate_memory(char **file_name) {
    
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

int count_number_characters(char *file_name) {

    FILE *fptr;
    char ch;
    int count_chars = 0;

    fptr = fopen(file_name, "r");

    while((ch = fgetc(fptr)) != EOF) {
        count_chars++;
    }

    fclose(fptr);

    return count_chars;
    
}

int count_lines_file(char *file_name) {

    FILE *fptr;
    char ch;
    int count_lines = 0;

    fptr = fopen(file_name, "r");

    while((ch = fgetc(fptr)) != EOF) {
        if(ch == '\n') {
            count_lines++;
        }
    }

    // Check if the last line doesn't end with a newline character
    if(count_lines > 0) {
        fseek(fptr, -1, SEEK_END); // Move one character before the end of the file
        if (getc(fptr) != '\n') {
            count_lines++;
        }
    }

    fclose(fptr);

    return count_lines;

}

int count_words_file(char *file_name) {

    FILE *fptr;
    char ch;
    int count_words = 0, is_word = 0;

    fptr = fopen(file_name, "r");

    while((ch = fgetc(fptr)) != EOF) {
        if(ch == 32 || ch == '\t' || ch == 10 || ch == 13) {
            is_word = 0;
        } else {
            if(!is_word) {
                count_words++;
                is_word = 1;
            }
        }
    }

    fclose(fptr);

    return count_words;

}

void data_output(char *file_name) {

    int total_chars = count_number_characters(file_name);
    int total_lines = count_lines_file(file_name);
    int total_words = count_words_file(file_name);

    puts("\n*** RESULTS ***\n");
    printf("1) Total number of characters in the file '%s': %d;\n", file_name, total_chars);
    printf("2) Total number of lines in the file '%s': %d;\n", file_name, total_lines);
    printf("3) Total number of words in the file '%s': %d.\n", file_name, total_words);

}

void count_chars_repetitions(char *file_name) {

    FILE *fptr;
    char ch, ch_lowercase, alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int size = sizeof(alphabet) / sizeof(alphabet[0]);
    int *count_repetitions;

    // Allocate memory dynamically for the "count_repetitions" array
    count_repetitions = (int *)calloc(size, sizeof(int));

    fptr = fopen(file_name, "r");

    while ((ch = fgetc(fptr)) != EOF) {
        if(ch >= 65 && ch <= 90) {
            ch_lowercase = ch + 32;
        } else {
            ch_lowercase = ch;
        }
        for(int i = 0; i < size; i++) {
            if(ch_lowercase == alphabet[i]) {
                count_repetitions[i]++;
            }
        }
    }

    fclose(fptr);

    // Print the counts
    printf("\n*** CHARACTER REPETITION COUNT ***\n\n");
    for(int i = 0; i < size; i++) {
        if (count_repetitions[i] > 0) {
            printf("-> Character '%c' appears %d times\n", alphabet[i], count_repetitions[i]);
        }
    }

    // Free the dynamically allocated memory
    free(count_repetitions);

}