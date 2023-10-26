#include <stdio.h>

int main() {

    int numbers[10], size = sizeof(numbers)/sizeof(numbers[0]), num, count = 0;

    for(int i = 0; i < size; i++) {
        printf("Enter the %dº number, please: ", (i+1));
        scanf("%d", &numbers[i]);
    }

    printf("\nRead an integer number, please:\n");
    scanf("%d", &num);

    printf("\n *** MULTIPLES OF %d ***\n-> ", num);
    for(int j = 0; j < size; j++) {
        if(numbers[j] % num == 0) {
            printf("%d ", numbers[j]);
            count++;
        }
    }

    printf("\n-> The total amount of integer numbers is %d\n", count);

    return 0;

}