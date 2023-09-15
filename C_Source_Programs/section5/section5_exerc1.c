#include <stdio.h>

int main() {

    printf("The first five multiples of 3 greater than zero are:\n");

    for(int i = 1; i <= 5; i++){

        printf("%d ", (3 * i));

    }

    printf("\n");

    return 0;

}