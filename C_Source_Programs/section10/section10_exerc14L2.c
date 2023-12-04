#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions prototype
int data_input(char **str1);
int test_mem_alloc(char *str);
void fill_positions_array(char *str, char *array_string);
void print_array(int size_array, char *array_string);

int main() {

    char *str;

    int size_array = data_input(&str);

    // Dynamically allocate memory for array_string
    char *array_string = (char *)malloc(size_array * sizeof(char));

    // Check for memory allocation failure
    if(test_mem_alloc(array_string)) {
        exit(1);
    }

    fill_positions_array(str, array_string);

    print_array(size_array, array_string);

    // Free the allocated memory
    free(str);
    free(array_string);

    // Setting the pointer to NULL after freeing the memory to avoid wild pointers (pointers that do not point to a valid object of the appropriate type)
    str = NULL;
    array_string = NULL;

    return 0;

}

int data_input(char **str){

    // Use malloc to dynamically allocate memory for the string
    *str = (char *)malloc(100 * sizeof(char));

    if(test_mem_alloc(*str)) {
        exit(1);
    }

    printf("*** DATA INPUT ***\n\n");

    // Input strings (including spaces)
    printf("Enter the string, please (including spaces):\n-> ");
    scanf(" %[^\n]", *str);

    // Reallocate memory with the correct size of the entered string
    *str = (char *)realloc(*str, (strlen(*str) + 1) * sizeof(char));

    if(test_mem_alloc(*str)) {
        exit(1);
    }

    int size_string = strlen(*str);

    return size_string;

}

int test_mem_alloc(char *str) {
    if (str == NULL) {
        printf("Memory (re)allocation failed.\n");
        return 1;
    }
    return 0;
}

void fill_positions_array(char *str, char *array_string) {

    for(size_t i = 0; i < strlen(str); i++) {
        *(array_string + i) = *(str + i);
    }

}

void print_array(int size_array, char *array_string) {

    printf("\n*** DATA OUTPUT ***\n\n");
    for(int i = 0; i < size_array; i++) {
        printf("array_string[%d]: %c\n", i, *(array_string + i));
    }

    putchar('\n');

}
