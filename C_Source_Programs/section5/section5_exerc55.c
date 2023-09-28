#include <stdio.h>

int main() {

    int num, countDiv = 0, totalPrime = 1, sumPrime = 0;

    do {

        printf("Enter an integer number, please:\n");
        scanf("%d", &num);

        if(num < 0) {
            printf("The integer number needs to be equal to or greater than 0. Enter a new integer number, please:\n");
            scanf("%d", &num);
        }

    } while(num < 0);

    for(int i = 1; totalPrime <= num; i++) {
        
        for(int j = 1; j <= i; j++) {
            if(i % j == 0) {
                countDiv++;
            }
        }

        if(countDiv == 2) {
            sumPrime += i;
            totalPrime++;
        }

        countDiv = 0;

    }

    printf("The sum of %dº first prime numbers is %d.\n", num, sumPrime);
    
    return 0;

}