#include <stdio.h>

int main(){

    int number, sumDigits = 0;

    printf("Enter an integer number, please:\n");
    scanf("%d", &number);

    if (number > 0){
        while (number != 0){
            sumDigits += (number % 10);
            number /= 10;
        }

        printf("The sum of all algorithms is %d.\n", sumDigits);

    }      
    else {
        printf("Invalid number!");
    }

    return 0;

}