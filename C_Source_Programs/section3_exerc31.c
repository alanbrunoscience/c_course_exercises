#include <stdio.h>

int main(){

    int number, previousNum, nextNum;

    printf("Enter the integer value, please:\n");
    scanf("%d", &number);

    previousNum = number - 1;
    nextNum = number + 1;

    printf("-> The previous number from %d is %d.\n", number, previousNum);
    printf("-> The next number from %d is %d.\n", number, nextNum);

    return 0;

}