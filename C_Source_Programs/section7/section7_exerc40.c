#include <stdio.h>

int main() {

    int numbers[10], size = sizeof(numbers) / sizeof(numbers[0]), count = 0, minor = 0, temp = 0;

    for(int i = 0; i < size; i++) {
        printf("Enter the %dº integer number, please:\n", (i + 1));
        scanf("%d", &numbers[i]);

        for(int j = 0; j < i; j++) {
            if(numbers[i] < numbers[j]) {
                temp = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = temp;
            }
        }
    }

    printf("\n*** SORTED ARRAY ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;

}