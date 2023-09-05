#include <stdio.h>

int main(){

    int number;

    printf("Enter an integer number, please:\n");
    scanf("%d", &number);

    if (number % 3 == 0 && number % 5 == 0) {
        printf("False\n");
    } else if (number % 3 == 0 || number % 5 == 0) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    
    return 0;

}