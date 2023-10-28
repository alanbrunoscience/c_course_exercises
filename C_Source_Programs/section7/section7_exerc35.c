#include <stdio.h>

int main() {

    int numbers[15], size = sizeof(numbers) / sizeof(numbers[0]);

    for(int i = 0; i < size; i++) {
        printf("Enter the %dº number, please: ", (i+1));
        scanf("%d", &numbers[i]);
    }

    for(int i = 0; i < size; i++) {
        if(numbers[i] == 0) {
            for(int j = i; j < size; j++){
                numbers[j] = numbers[j + 1];
            }
            size--;
        }
    }

    printf("\n*** NEW ARRAY (WITHOUT ZEROS) ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;

}