#include <stdio.h>

int main () {

    int num;

    printf("Enter an integer number, please:\n");
    scanf("%d", &num);

    printf("1");

    for(int i = 2; i <= num; i++) {
        printf(" + %d", i);
    }

    printf("\n");

    return 0;

}