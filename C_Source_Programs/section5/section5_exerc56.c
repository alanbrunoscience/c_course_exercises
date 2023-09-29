#include <stdio.h>

int main() {

    int countDiv = 0, sumPrime = 0, num = 2000000;

    for(int i = 1; i < num; i++) {
        for(int j = 1; j <= i; j++) {
            if(i % j == 0) {
                countDiv++;
            }
        }

        if(countDiv == 2) {
            sumPrime += i;
        }

        countDiv = 0;

    }

    printf("The sum of all prime numbers smaller than %d is %d.\n", num, sumPrime);

    return 0;

}