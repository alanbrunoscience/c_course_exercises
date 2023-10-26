#include <stdio.h>

int main()
{

    int numbers[100], size = sizeof(numbers) / sizeof(numbers[0]), index = 0;

    for (int i = 0; i < size; i++) {
        if (index % 7 != 0 && index % 10 != 7 || index == 0) {
            numbers[i] = index;
            index++;
        } else {
            if((index + 1) % 10 == 7 || (index + 1) % 7 == 0){
                numbers[i] = index + 2;
                index += 3;
            } else {
                numbers[i] = index + 1;
                index += 2;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("numbers[%d]: %d\n", i, numbers[i]);
    }

    return 0;
}