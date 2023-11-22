#include <stdio.h>

// Functions prototype
char dataInput(char character);
char toUpper(char charValidated);

int main() {

    char inputChar;
    int charValidated;

    charValidated = dataInput(inputChar);

    printf("\n-> The uppercase character corresponding to '%c' is '%c'.\n", charValidated, toUpper(charValidated));

    return 0;

}

char dataInput(char inputChar) {
    
    printf("Enter a lowercase character (a - z), please: ");
    scanf("%s", &inputChar);

    while(inputChar < 97 ||  inputChar > 122) {
        printf("\n*** The character entered is not valid. Enter a new character between 'a' and 'z' (including), please! ***\n-> ");
        scanf("%s", &inputChar);
    }

    return inputChar;

}

char toUpper(char charValidated) {
    
    int charUppercase;

    charUppercase = charValidated - 32;

    return charUppercase;

}
