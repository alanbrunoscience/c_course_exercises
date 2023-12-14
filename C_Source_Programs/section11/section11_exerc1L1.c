#include <stdio.h>
#include <stdlib.h>

// Functions prototype
void write_file(char *chars, char *name_file);
void read_file(char *chars, char *name_file);

int main() {
    char chars[20], name_file[] = {"file.txt"};

    write_file(chars, name_file);
    read_file(chars, name_file);

    return 0;
}

void write_file(char *chars, char *name_file) {

    FILE *fptr = fopen(name_file, "w");

    puts("********************** WRITING IN THE FILE **********************\n");

    if (fptr == NULL) {
        puts("It was not possible to open the file.");
        exit(1);
    }

    printf("Enter a set of characters up to 20 characters, or press 0 to exit:\n-> ");
    fgets(chars, 20, stdin);

    while (chars[0] != '0') {
        fputs(chars, fptr);
        printf("\nEnter a set of characters up to 20 characters, or press 0 to exit:\n-> ");
        fgets(chars, 20, stdin);
    }

    fclose(fptr);

}

void read_file(char *chars, char *name_file) {

    FILE *fptr = fopen(name_file, "r");

    puts("\n************************ READING THE FILE ************************\n");

    if (fptr == NULL) {
        puts("It was not possible to open the file.");
        exit(1);
    }

    while (fgets(chars, 20, fptr) != NULL) {
        printf("%s", chars);
    }

    fclose(fptr);

}
