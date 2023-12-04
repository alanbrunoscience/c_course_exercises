#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions prototype
void data_input(char **str);
int test_mem_alloc(char *str);
void print_array(char *str);

int main() {

    char *str;

    data_input(&str);

    print_array(str);

    // Free the allocated memory
    free(str);

    // Setting the pointer to NULL after freeing the memory to avoid wild pointers (pointers that do not point to a valid object of the appropriate type)
    str = NULL;

    return 0;

}

void data_input(char **str) {

    // Allocate memory dynamically for the string
    *str = (char *)malloc(100 * sizeof(char));

    if(test_mem_alloc(*str)) {
        exit(1);
    }

    printf("Enter the string, please (including spaces): ");
    scanf(" %[^\n]", *str);

    // Reallocate memory with the correct size of the string
    *str = (char *)realloc(*str, (strlen(*str) + 1) * sizeof(char));

    if(test_mem_alloc(*str)) {
        exit(1);
    }

}

int test_mem_alloc(char *str) {
    if(str == NULL) {
        printf("Memory (re)allocation failed.\n");
        return 1;
    }
    return 0;
}

void print_array(char *str) {

    printf("\n-> ");

    for(size_t i = 0; i < strlen(str); i++) {
        printf("%c", *(str + i));
    }

    putchar('\n');

}