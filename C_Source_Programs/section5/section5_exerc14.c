#include <stdio.h>

int main() {

    int num;

    do {

        printf("Enter an even integer, please:\n");
        scanf("%d", &num);

        if(num % 2 != 0) {
            printf("\n*** The number entered is not valid because it is not even. Enter an even integer again ***\n\n");
        }

    } while(num % 2 != 0);

    for(int i = num; i >= 0; i--) {

        if(i % 2 == 0) {
            printf("%d ", i);
        }

    }

    printf("\n");

    return 0;

}