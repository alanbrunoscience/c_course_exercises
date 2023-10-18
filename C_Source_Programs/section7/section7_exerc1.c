#include <stdio.h>

int main() {

    int numbers[6], sum = 0;

    for(int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++){
        printf("Enter the %dº integer number, please: ", (i + 1));
        scanf("%d", &numbers[i]);
        getchar();
    }

    sum = numbers[0] + numbers[1] + numbers[5];
    printf("\nThe sum of values of number[0], number[1] and number[5] is %d.\n\n", sum);

    numbers[4] = 100;

    for(int j = 0; j < sizeof(numbers)/sizeof(numbers[0]); j++) {
        printf("numbers[%d] = %d\n", j, numbers[j]);
    }

    return 0;

}