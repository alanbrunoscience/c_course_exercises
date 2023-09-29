#include <stdio.h>

int main() {

    int a, b, countPrime = 0, countDiv = 0;

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
                countPrime++;
            }

            countDiv = 0;

        }

        printf("Between %d and %d there is (are) %d prime numbers.\n", a, b, countPrime);

    } else {
        
        for(int i = b; i <= a; i++) {
            for(int j = 1; j <= i; j++) {
                if(i % j == 0) {
                    countDiv++;
                }
            }

            if(countDiv == 2) {
                countPrime++;
            }

            countDiv = 0;

        }

        printf("Between %d and %d there is (are) %d prime numbers.\n", b, a, countPrime);

    }

    return 0;

}