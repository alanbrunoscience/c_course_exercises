#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50

// Functions prototype
void file_input_name(char **file_name);
int validate_file_existence(char *file_name);
void allocate_memory(char **file_name);
void reallocate_memory(char **file_name);
int validate_mem_alloc(char *file_name);
void count_repetition_word_file(char *file_name);

int main() {

    char *file_name;

    file_input_name(&file_name);
    count_repetition_word_file(file_name);

    free(file_name);

    return 0;

}

void file_input_name(char **file_name) {

    allocate_memory(file_name);

    printf("*** DATA INPUT ***\n\n");
    printf("1) Enter the name of the file to be read: ");
    scanf(" %[^\n]%*c", *file_name);

    while(validate_file_existence(*file_name)) {
        printf("\n-> It was not possible to open the file. Make sure that this file exists or that the name is correct. Inform the name of the file again: ");
        scanf(" %[^\n]%*c", *file_name);
    }

    reallocate_memory(file_name);

}

int validate_file_existence(char *file_name) {

    FILE *fptr;

    fptr = fopen(file_name , "r");

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

void count_repetition_word_file(char *file_name) {
    
    FILE *fptr;
    char *word = NULL, ch;
    size_t len = 0;
    ssize_t bytesRead;
    unsigned long long total_chars = 0, aux, count_words = 0;
    int count_chars;

    printf("\n2) Enter a word to be searched for in the previously informed file, to count repetitions: ");
    bytesRead = getline(&word, &len, stdin);

    if (bytesRead == -1) {
        perror("Error reading input");
        free(word);
        exit(EXIT_FAILURE);
    }

    if (bytesRead > 0 && word[bytesRead - 1] == '\n') {
        word[bytesRead - 1] = '\0';
    } else {
        printf("Warning: Input line is too long and may be truncated.\n");
    }

    fptr = fopen(file_name, "r");

    while((ch = fgetc(fptr)) != EOF) {
        total_chars++;
    }

    fseek(fptr, 0, SEEK_SET);

    char chars_file[total_chars + 1];

    unsigned long long i = 0;

    while((ch = fgetc(fptr)) != EOF) {
        chars_file[i] = ch;
        i++;
    }

    chars_file[total_chars] = '\0';

    for(size_t i = 0; i <= strlen(chars_file) - strlen(word); i++) {
        if(word[0] == chars_file[i]) {
            aux = i;
            count_chars = 0;
            for(size_t j = 0; j < strlen(word); j++) {
                if(word[j] == chars_file[aux]) {
                    count_chars++;
                    aux++;
                }
            }

            if(count_chars == (int)strlen(word)) {
                count_words++;
                i = aux - 1;
            }
        }
    }

    if(count_words > 0) {
        printf("\n-> The word '%s' repeats %lld time(s) in the file.\n", word, count_words);
    } else {
        printf("\n-> The word '%s' doesn't repeat at any time in the file.\n", word);
    }
    
    free(word);

    fclose(fptr);

}