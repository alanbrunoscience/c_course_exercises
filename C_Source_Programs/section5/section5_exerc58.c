#include <stdio.h>

int main() {

    int a, b, sumPrime = 0, countDiv = 0;

    printf("Enter the first number, please:\n");
    scanf("%d", &a);

    printf("Enter the second number, please:\n");
    scanf("%d", &b);

    if(a < b) {
        
        for(int i = a; i <= b; i++) {
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

        printf("The sum of all prime numbers between %d and %d is %d.\n", a, b, sumPrime);

    } else {
        
        for(int i = b; i <= a; i++) {
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

        printf("The sum of all prime numbers between %d and %d is %d.\n", b, a, sumPrime);

    }

    return 0;

}