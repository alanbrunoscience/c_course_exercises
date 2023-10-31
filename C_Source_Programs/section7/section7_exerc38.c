#include <stdio.h>

int main() {

    int numbers[10], size = sizeof(numbers) / sizeof(numbers[0]), minor = 0, temp = 0;

    for(int i = 0; i < size; i++) {
        printf("Enter the %dº integer number, please:\n", (i + 1));
        scanf("%d", &numbers[i]);
    }

    for(int i = 0; i < size; i++) {
        minor = i;
        for(int j = minor + 1; j < size; j++) {
            if(numbers[j] < numbers[minor]) {
                minor = j;
            }
        }
        temp = numbers[i];
        numbers[i] = numbers[minor];
        numbers[minor] = temp;
    }

    printf("\n*** SORTED ARRAY ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;

}