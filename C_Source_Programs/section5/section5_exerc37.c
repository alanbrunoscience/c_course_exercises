#include <stdio.h>
#include <math.h>

int main() {

    int sumFirstDigits, sumLastDigits, sqrSumDigits;

    for(int i = 1000; i <= 9999; i++) {
        sumFirstDigits = i / 100;
        sumLastDigits = i % 100;

        sqrSumDigits = pow((sumFirstDigits + sumLastDigits), 2);

        if(sqrSumDigits == i) {
            printf("%d ", sqrSumDigits);
        }
    }

    printf("\n");

    return 0;

}