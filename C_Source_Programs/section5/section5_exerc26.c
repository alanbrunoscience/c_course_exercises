#include <stdio.h>

int main() {

    int num;

    printf("Enter an integer number, please:\n");
    scanf("%d", &num);

    for(int i = 0; i <= num; i++) {

        if(i % 11 == 0 || i % 13 == 0 || i % 17 == 0) {
            printf("%d ", i);
        }

    }

    printf("\n");

    return 0;

}