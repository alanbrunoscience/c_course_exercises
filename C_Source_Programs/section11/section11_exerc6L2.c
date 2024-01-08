#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void file_name_input(char **file_name);
int validate_mem_allocation(char *file_name);
void count_chars_repetitions(char *file_name);

int main() {
    char *file_name;

    file_name_input(&file_name);
    count_chars_repetitions(file_name);

    free(file_name);

    return 0;
}

void file_name_input(char **file_name) {
    *file_name = (char *)malloc(100 * sizeof(char));

    if (validate_mem_allocation(*file_name)) {
        exit(1);
    }

    printf("*** DATA INPUT ***\n\n");
    printf("Enter the name of the file: ");
    scanf(" %[^\n]", *file_name);

    *file_name = (char *)realloc(*file_name, (strlen(*file_name) + 1) * sizeof(char));

    if (validate_mem_allocation(*file_name)) {
        exit(1);
    }
}

int validate_mem_allocation(char *file_name) {
    if (file_name == NULL) {
        puts("\n-> Memory (re)allocation failed.");
        return 1;
    }
    return 0;
}

void count_chars_repetitions(char *file_name) {
    FILE *fptr;
    char c, alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int size = sizeof(alphabet) / sizeof(alphabet[0]);
    int *count_repetitions;

    // Allocate memory dynamically for the "count_repetitions" array
    count_repetitions = (int *)calloc(size, sizeof(int));

    fptr = fopen(file_name, "r");

    if (fptr == NULL) {
        puts("\n-> Unable to open the file.");
        exit(1);
    }

    while ((c = fgetc(fptr)) != EOF) {
        for(int i = 0; i < size; i++) {
            if(c == alphabet[i]) {
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
