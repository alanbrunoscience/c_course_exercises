#include <stdio.h>

int main () {

    int num;

    printf("Enter an integer number, please:\n");
    scanf("%d", &num);

    printf("1");

    for(int i = 2; i <= (2 * num - 1); i++) {
        if(i % 2 != 0) {
            printf(" + %d", i);
        } 
    }

    printf("\n");

    return 0;

}