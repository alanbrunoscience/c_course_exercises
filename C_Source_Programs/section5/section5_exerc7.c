#include <stdio.h>

int main() {

    int number, sum = 0;
    float average;

    for(int i = 0; i < 10; i++) {
            
        printf("Enter the %dº number, please:\n", (i+1));
        scanf("%d", &number);

        while(number < 0) {
            printf("The informed number is invalid. It needs to be greater or equal to zero. Enter %dº number again:\n", (i+1));
            scanf("%d", &number);
        }

        sum += number;
    
    }

    average = (float) sum / 10;
    
    printf("The average of the informed values is %.2f.\n", average);

    return 0;

}