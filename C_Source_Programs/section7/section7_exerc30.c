#include <stdio.h>

int main() {

    int numbers[10], size = sizeof(numbers) / sizeof(numbers[0]), newArray[10], arrayEven[10], arrayOdd[10], countArray = 0, countEven = 0, countOdd = 0, minor, temp;

    // Data Input
    for(int i = 0; i < size; i++) {
        printf("Enter the %dº number, please: ", (i+1));
        scanf("%d", &numbers[i]);
    }

    // Sorting the array
    for(int i = 0; i < size; i++) {
        minor = i;
        for(int j = i + 1; j < size; j++) {
            if(numbers[j] < numbers[minor]) {
                minor = j;
            }
        }
        temp = numbers[i];
        numbers[i] = numbers[minor];
        numbers[minor] = temp;
    }

    // Removing duplicate elements in the array
    for(int i = 0; i < size; i++) {
        if(numbers[i] != numbers[i+1]) {
            newArray[countArray] = numbers[i];
            countArray++;
        }
    }

    // Find even and odd numbers
    for(int i = 0; i < countArray; i++) {
        if(newArray[i] % 2 == 0) {
            arrayEven[countEven] = newArray[i];
            countEven++;
        } else {
            arrayOdd[countOdd] = newArray[i];
            countOdd++;
        }
    }

    // Array sorted and without duplicate elements
    printf("\n*** NEW ARRAY ***\n\n");
    for(int i = 0; i < countArray; i++) {
        printf("newArray[%d]: %d\n", i, newArray[i]);
    }

    // Print arrays of even and odd elements
    printf("\n*** ARRAY OF EVEN ELEMENTS ***\n\n");
    for(int i = 0; i < countEven; i++) {
        printf("arrayEven[%d]: %d\n", i, arrayEven[i]);
    }

    printf("\n*** ARRAY OF ODD ELEMENTS ***\n\n");
    for(int i = 0; i < countOdd; i++) {
        printf("arrayOdd[%d]: %d\n", i, arrayOdd[i]);
    }

    return 0;

}