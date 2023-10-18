#include <stdio.h>

int main() {

    int numbers[6];

    for(int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        printf("Enter the %dº integer value, please: ", (i+1));
        scanf("%d", &numbers[i]);
        getchar();
    }

    printf("\n");
    
    for(int j = 0; j < sizeof(numbers) / sizeof(numbers[0]); j++) {
        printf("numbers[%d] = %d\n", j, numbers[j]);
    }

    return 0;

}