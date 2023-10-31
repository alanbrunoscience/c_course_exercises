#include <stdio.h>

int main() {

    int numbers[] = {1, 2, 3, 4, 5, 12, 11, 10, 9, 8, 7, 6}, size = sizeof(numbers) / sizeof(numbers[0]), minor = 0, temp = 0;


    for(int i = 5; i < size; i++) {
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