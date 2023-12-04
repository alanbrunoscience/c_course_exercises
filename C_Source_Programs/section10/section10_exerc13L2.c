#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions prototype
void data_input(char **str1, char **str2);
int test_mem_alloc(char *string);
int validate_s1_in_s2(char *str1, char *str2);

int main() {

    char *str1, *str2;

    data_input(&str1, &str2);

    validate_s1_in_s2(str1, str2);

    if(validate_s1_in_s2(str1, str2)){
        printf("\nTrue\n");
    } else {
        printf("\nFalse\n");
    }

    // Free the allocated memory
    free(str1);
    free(str2);

    // Setting the pointer to NULL after freeing the memory to avoid wild pointers (pointers that do not point to a valid object of the appropriate type)
    str1 = NULL;
    str2 = NULL;

    return 0;

}

void data_input(char **str1, char **str2) {

    // Use malloc to dynamically allocate memory for the strings
    *str1 = (char *)malloc(100 * sizeof(char));
    *str2 = (char *)malloc(100 * sizeof(char));

    if (test_mem_alloc(*str1) || test_mem_alloc(*str2)) {
        exit(1);
    }

    printf("*** DATA INPUT ***\n\n");

    // Input strings (including spaces)
    printf("Enter the first string, please (including spaces):\n-> ");
    scanf(" %[^\n]", *str1);

    // Reallocate memory with the correct size of the string "str1"
    *str1 = (char *)realloc(*str1, (strlen(*str1) + 1) * sizeof(char));

    if (test_mem_alloc(*str1)) {
        exit(1);
    }

    printf("\n");

    printf("Enter the second string, please (including spaces):\n-> ");
    scanf(" %[^\n]", *str2);

    // Reallocate memory with the correct size of the string "str2"
    *str2 = (char *)realloc(*str2, (strlen(*str2) + 1) * sizeof(char));

    if (test_mem_alloc(*str2)) {
        exit(1);
    }

}

int test_mem_alloc(char *string) {
    if (string == NULL) {
        printf("Memory (re)allocation failed.\n");
        return 1;
    }
    return 0;
}

int validate_s1_in_s2(char *str1, char *str2) {

    if(strlen(str1) < strlen(str2)) {
        return 0;
    }

    if(strcmp(str1, str2) == 0) {
        return 1;
    }

    int aux, countChar;

    for(size_t i = 0; i <= strlen(str1) - strlen(str2); i++) {   

        if(str2[0] == str1[i]) {
            
            aux = i;
            countChar = 0;
            
            for(size_t k = 0; k < strlen(str2); k++) {
                if(str2[k] == str1[aux]) {
                    countChar++;
                    aux++;
                }
            }

            if(countChar == (int)strlen(str2)) {
                return 1;
                break;
            }
        }
    }

    if(countChar != (int)strlen(str2)) {
        return 0;
    }

    return -1;

}