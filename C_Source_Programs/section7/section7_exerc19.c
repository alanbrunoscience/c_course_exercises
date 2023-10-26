#include <stdio.h>

int main() {

    int numbers[50], size = sizeof(numbers) / sizeof(numbers[0]);

    for(int i = 0; i < size; i++) {
        printf("numbers[%d] = %d\n", (i+1), ((i + 5 * i)%(i + 1)));
    }

    return 0;

}