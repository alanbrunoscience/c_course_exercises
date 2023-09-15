#include <stdio.h>

int main() {

    int num;

    do {

        printf("Enter an odd integer, please:\n");
        scanf("%d", &num);

        if(num % 2 == 0) {
            printf("\n*** The number entered is not valid because it is not odd. Enter an odd integer again ***\n\n");
        }

    } while(num % 2 == 0);

    for(int i = 1; i <= num; i++) {

        if(i % 2 != 0) {
            printf("%d ", i);
        }

    }

    printf("\n");

    return 0;

}