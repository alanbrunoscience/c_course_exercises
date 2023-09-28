#include <stdio.h>

int main () {

    int num, countDiv = 0;

    printf("Enter an integer number, please:\n");
    scanf("%d", &num);

    for(int i = 1; i <= num; i++) {
        if(num % i == 0) {
            countDiv++;
        }
    }

    if(countDiv == 2) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d isn't a prime number.\n", num);
    }

    return 0;

}