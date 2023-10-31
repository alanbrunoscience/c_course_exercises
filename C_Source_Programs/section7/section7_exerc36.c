#include <stdio.h>

int main() {

    int numbers[10], size = sizeof(numbers) / sizeof(numbers[0]);

    for(int i = 0; i < size; i++) {
        printf("Enter the %dº integer number, please:\n", (i+1));
        scanf("%d", &numbers[i]);
        for(int j = 0; j < i; j++) {
            while(numbers[i] == numbers[j]) {
                printf("\n*** The number %d is already on the list. Insert the %dº number again! ***\n-> ", numbers[i], (i+1));
                scanf("%d", &numbers[i]);
                printf("\n");
            }
        }

    }

    // Data output
    printf("\n*** FINAL ARRAY ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;

}