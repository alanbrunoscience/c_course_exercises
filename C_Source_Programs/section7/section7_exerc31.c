#include <stdio.h>

int main() {

    int numbers[6], size = sizeof(numbers) / sizeof(numbers[0]), numEven[6], numOdd[6], countEven = 0, sumEven = 0, countOdd = 0;

    for(int i = 0; i < size; i++) {
        printf("Enter the %dº integer value, please: ", (i+1));
        scanf("%d", &numbers[i]);
    }

    for(int i = 0; i < size; i++) {
        if(numbers[i] % 2 == 0) {
            numEven[countEven] = numbers[i];
            sumEven += numbers[i];
            countEven++;
        } else {
            numOdd[countOdd] = numbers[i];
            countOdd++;
        }
    }

    printf("\n*** RESULTS ***\n\n");
    printf("-> Even numbers: ");
    for(int i = 0; i < countEven; i++) {
        printf("%d ", numEven[i]);
        if(i == (countEven - 1)){
            printf("\n");
        }
    }
    printf("-> The sum of all even numbers: %d\n", sumEven);
    printf("-> Odd numbers: ");
    for(int i = 0; i < countOdd; i++) {
        printf("%d ", numOdd[i]);
        if(i == (countOdd - 1)) {
            printf("\n");
        }
    }
    printf("-> The number of odd numbers entered: %d\n", countOdd);

    return 0;

}