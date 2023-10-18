#include <stdio.h>

int main() {

    int numbers[6];

    for(int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        printf("Enter the %dº value (numbers[%d]), please: ", (i+1), i);
        scanf("%d", &numbers[i]);
    }

    printf("\n");

    for(int i = (sizeof(numbers) / sizeof(numbers[0])) - 1; i >= 0 ; i--) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    return 0;

}