#include <stdio.h>

int main() {

    int numbers[10], size = sizeof(numbers)/sizeof(numbers[0]);

    for(int i = 0; i < size; i++) {
        printf("Enter the %dº number, please: ", (i+1));
        scanf("%d", &numbers[i]);

        if(numbers[i] < 0) {
            printf("\n*** The number %d is being changed by 0 because it's smaller than 0 ***\n\n", numbers[i]);
            numbers[i] = 0;
        }
    }

    printf("\n *** PRINT ARRAY'S ELEMENTS ***\n\n");
    for(int j = 0; j < size; j++) {
        printf("numbers[%d]: %d\n", (j+1), numbers[j]);
    }

    return 0;

}