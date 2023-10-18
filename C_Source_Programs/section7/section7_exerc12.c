#include <stdio.h>

int main() {

    int numbers[5], size = sizeof(numbers) / sizeof(numbers[0]), major, minor, sumNumbers = 0;
    float average;

    printf("Enter the 1º integer number (numbers[0]), please: ");
    scanf("%d", &numbers[0]);

    major = numbers[0];
    minor = numbers[0];
    sumNumbers += numbers[0];

    for(int i = 1; i < size; i++) {
        printf("Enter the %dº integer number (numbers[%d]), please: ", (i+1), i);
        scanf("%d", &numbers[i]);

        sumNumbers += numbers[i];

        if(major < numbers[i]) {
            major = numbers[i];
        }

        if(minor > numbers[i]) {
            minor = numbers[i];
        }

    }

    average = (float)sumNumbers / (float)size;

    printf("\n*** RESULTS ***\n\n");
    printf("-> Largest number: %d;\n", major);
    printf("-> Smallest number: %d;\n", minor);
    printf("-> Average: %.2f.\n", average);

    return 0;

}

