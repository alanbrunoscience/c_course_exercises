#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char letter[2];

    printf("Enter a letter, please: ");
    scanf(" %1c", letter);

    printf("The letter inserted is %c.\n", letter[0]);

    return 0;

}