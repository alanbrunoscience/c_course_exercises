#include <stdio.h>

int main () {

    int num, sum = 0;

    do {

        printf("Enter an integer number greater or equal to zero, please:\n");
        scanf("%d", &num);

        if(num < 0) {
            printf("\n*** The number entered is not valid because it is smaller than zero. Enter a valid integer number again ***\n\n");
        }

    } while(num < 0);

    for(int i = 0; i <= num; i++) {
        
        printf("%d", i);
        sum += i;

        if(i < num) {
            printf(" + ");
        } else {
            printf(" = ");
        }
        
    }

    printf("%d\n", sum);

    return 0;

}