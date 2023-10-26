#include <stdio.h>

int main() {

    int numbers[10], oddNumbers[10], size = sizeof(numbers)/sizeof(numbers[0]), count = 0;

    for(int i = 0; i < size; i++) {
        printf("Enter the %dº number, please: ", (i+1));
        scanf("%d", &numbers[i]);

        if(numbers[i] < 0 || numbers[i] > 50) {
            printf("\n*** The number entered is invalid. The number needs to be between 0 and 50 (including). Enter the %dº number again ***\n-> ", (i+1));
            scanf("%d", &numbers[i]);
            printf("\n");
        }

        if(numbers[i] % 2 != 0) {
            oddNumbers[count] = numbers[i];
            count++;
        }
    }

    printf("\n*** PRINT ARRAY'S ELEMENTS ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("numbers[%d]: %d\n", i, numbers[i]);
    }

    printf("\n*** PRINT ARRAY'S ODD ELEMENTS ***\n\n");
    for(int i = 0; i < count; i++) {
        printf("oddNumbers[%d]: %d\n", i, oddNumbers[i]);
    }

    return 0;

}