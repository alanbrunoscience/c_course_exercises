#include <stdio.h>

int main(){

    int num, sum;

    printf("Enter the integer number, please:\n");
    scanf("%d", &num);

    sum = (((num * 3) + 1) + ((num * 2) - 1));

    printf("The sum is %d\n", sum);

    return 0;

}