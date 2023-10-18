#include <stdio.h>

int main() {

    int numbers[6], sizeArray = sizeof(numbers) / sizeof(numbers[0]);

    for(int i = 0; i < sizeArray; i++) {
        printf("Enter the %dº integer and even value, please: ", (i+1));
        scanf("%d", &numbers[i]);

        while(numbers[i] % 2 != 0){
            printf("The number is invalid! It is not an even number. Enter the %dº integer and even value, again: ", (i+1));
            scanf("%d", &numbers[i]);
        }

    }

    for(int j = (sizeArray)- 1; j >= 0; j--){
        printf("numbers[%d] = %d\n", j, numbers[j]);
    }

    return 0;

}