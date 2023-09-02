#include <stdio.h>

int main(){

    char uppercase, lowercase;

    printf("Type a capital letter, please:\n");
    scanf("%c", &uppercase);

    if(uppercase >= 'A' && uppercase <= 'Z'){

        lowercase = uppercase + 32;

        printf("The corresponding lowercase letter is: %c\n", lowercase);

    } else{
        printf("Input is not a valid uppercase letter.\n");
    }

    return 0;

}