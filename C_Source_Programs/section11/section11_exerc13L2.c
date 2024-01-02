#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define MAX_FILE_NAME_LENGTH 50

// Functions prototype
void file_name_input(char **file_name);
void allocate_memory(char **file_name);
void reallocate_memory(char **file_name);
int validate_mem_alloc(char *file_name);
void data_input_validation_file(char *file_name);
int validate_phone_number(char *phone_digits);
void write_content_file(char *file_name, char *name, char *phone_digits);
void print_content_file(char *file_name);

int main() {

    char *file_name;

    file_name_input(&file_name);
    data_input_validation_file(file_name);
    print_content_file(file_name);

    free(file_name);

    return 0;

}

void file_name_input(char **file_name) {

    allocate_memory(file_name);

    printf("*** FILE NAME ***\n\n");
    printf("1) Enter the name of the file to be created, please: ");
    scanf(" %[^\n]%*c", *file_name);

    reallocate_memory(file_name);

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

void data_input_validation_file(char *file_name) {

    char phone_digits[11];
    int i = 1;

    do {

        char *name = NULL;
        size_t buffer_size = 0;

        printf("\n*** DATA INPUT ***\n\n");
        printf("%dº CONTACT:\n\n", i);
        printf("1) Enter the full name: ");
        getline(&name, &buffer_size, stdin);

        for (size_t i = 0; name[i] != '\0'; i++) {
            if (name[i] == '\n') {
                name[i] = '\0';
                break;
            }
        }

        printf("2) Enter the 10-digit phone number, without parentheses, hyphens, or other special characters. Enter numbers only: ");
        scanf("%s%*c", phone_digits);

        while(validate_phone_number(phone_digits)) {
            printf("\n-> There are some special characters in the phone number. Enter the 10-digit phone number, without parentheses, hyphens, or other special characters: ");
            scanf("%s%*c", phone_digits);
        }

        if(phone_digits[0] == '0' && strlen(phone_digits) == 1) {
            puts("\nFinishing the program...");
            break;

        } else {

            while((strlen(phone_digits) >= 1 && strlen(phone_digits) < 10) || (strlen(phone_digits) > 10)) {
                printf("\n-> The phone number is invalid. It needs to have 10 digits. Enter the phone number again: ");
                scanf("%s%*c", phone_digits);

                while(validate_phone_number(phone_digits)) {
                    printf("\n-> There are some special characters in the phone number. Enter the 10-digit phone number, without parentheses, hyphens, or other special characters: ");
                    scanf("%s%*c", phone_digits);
                }

            }

            write_content_file(file_name, name, phone_digits);

        }

        i++;

    } while(phone_digits[0] != '0' && strlen(phone_digits) != 1);

}

int validate_phone_number(char *phone_digits) {

    for(size_t i = 0; phone_digits[i] != '\0'; i++) {
        if(phone_digits[i] < 48 || phone_digits[i] > 57) {
            return 1;
            break;
        }
    }

    return 0;

}

void write_content_file(char *file_name, char *name, char *phone_digits) {

    FILE *fptr;

    fptr = fopen(file_name, "a");

    if(fptr == NULL) {
        puts("\n-> Unable to open the file.");
        exit(1);
    } else {

        fputs("Name: ", fptr);

        fputs(name, fptr);

        free(name);

        fputs(" | ", fptr);

        fputs("Phone Number: +1 ", fptr);

        for(size_t i = 0; phone_digits[i] != '\0'; i++) {
            if(i == 0) {
                fputc('(', fptr);
            }

            if(i == 3) {
                fputs(") ", fptr);
            }

            if(i == 6) {
                fputc('-', fptr);
            }

            fputc(phone_digits[i], fptr);

        }

        fputc('\n', fptr);

        fclose(fptr);

    }

}

void print_content_file(char *file_name) {

    FILE *fptr;
    char *str = NULL;
    size_t len = 0;

    if ((fptr = fopen(file_name, "r")) == NULL) {
        puts("\n-> It was not possible to open the file for reading.");
        exit(1);
    }

    if(getline(&str, &len, fptr) == -1) {
        puts("\n-> The file is empty!");
        fclose(fptr);
    } else {

        fptr = fopen(file_name, "r");

        puts("\n****** PHONE BOOK ******\n");

        while(getline(&str, &len, fptr) != -1) {
            printf("%s", str);
        }

        printf("\n");

        free(str);

        fclose(fptr);

    }

}