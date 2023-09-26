#include <stdio.h>

int main () {

    int num, fib = 0, temp1, temp2 = 1;

    printf("Enter an integer number, please:\n");
    scanf("%d", &num);

    printf("0 ");

    do {
        temp1 = fib;
        fib += temp2;
        temp2 = temp1;
        printf("%d ", fib);
    } while(fib < num);

    printf("\n");

    return 0;

}