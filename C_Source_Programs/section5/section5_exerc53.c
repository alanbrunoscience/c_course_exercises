#include <stdio.h>

int main () {

    int num, aux = 1;

    printf("Enter an integer number, please:\n");
    scanf("%d", &num);

    for(int i = 1; i <= num; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", aux);
            aux += 1;
        }
        printf("\n");
    }

    return 0;

}