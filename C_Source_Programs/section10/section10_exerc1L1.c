#include <stdio.h>

// Functions prototype
void dataInput();
void changeValues(int *n1_ptr, float *n2_ptr, char *char_ptr);
void printValues(int *n1_ptr, float *n2_ptr, char *char_ptr);

int main(){

    dataInput();

    return 0;

}

void dataInput() {

    int n1;
    float n2;
    char character;

    printf("*** ORIGINAL VALUES ***\n\n");
    printf("Enter an integer, a real number, and a character respectively, please:\n");
    scanf("%d", &n1);
    scanf("%f", &n2);
    scanf(" %c", &character);

    int *n1_ptr = &n1;
    float *n2_ptr = &n2;
    char *char_ptr = &character;
    
    changeValues(n1_ptr, n2_ptr, char_ptr);

}

void changeValues(int *n1_ptr, float *n2_ptr, char *char_ptr) {

    int newN1;
    float newN2;
    char newChar;

    printf("\n\n*** NEW VALUES ***\n\n");
    printf("Enter a new integer, real number and character respectively:\n");
    scanf("%d", &newN1);
    scanf("%f", &newN2);
    scanf(" %c", &newChar);

    *n1_ptr = newN1;
    *n2_ptr = newN2;
    *char_ptr = newChar;

    printValues(n1_ptr, n2_ptr, char_ptr);

}

void printValues(int *n1_ptr, float *n2_ptr, char *char_ptr) {

    printf("\n\n*** VALUES MODIFIED ***\n\n");
    printf("-> New integer value: %d\n", *n1_ptr);
    printf("-> New real value: %.2f\n", *n2_ptr);
    printf("-> New char value: %c\n", *char_ptr);

}
