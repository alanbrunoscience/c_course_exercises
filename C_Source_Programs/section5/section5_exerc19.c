#include <stdio.h>

int main() {

    int num, algs[3];

    do {

        printf("Enter an integer number between 100 and 900 (both included), please:\n");
        scanf("%d", &num);

        if(num < 100 || num > 900) {
            printf("\n*** The number entered is not valid because it is not between 100 and 900 (both included). Enter an integer again ***\n\n");
        }

    } while(num < 100 || num > 900);

    for(int i = 2; i >= 0; i--) {
        algs[i] = num % 10;
        num /= 10;
    }

    for (int i = 0; i < 3; i++) {
        printf("%d ", algs[i]);
    }

    printf("\n");

    return 0;

}