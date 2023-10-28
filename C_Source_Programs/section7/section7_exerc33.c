#include <stdio.h>

int main() {

    int i = 0, arrayNum[20], newArray[10], size = sizeof(arrayNum) / sizeof(arrayNum[0]), minor, temp, count = 0;

    // Data Input
    printf("*** ARRAY A ***\n\n");
    for(; i < size / 2; i++) {
        printf("Enter the %dº number, please: ", (i+1));
        scanf("%d", &arrayNum[i]);
    }

    // Data Input
    printf("\n*** ARRAY B ***\n\n");
    for(; i < size; i++) {
        printf("Enter the %dº number, please: ", ((i - 10) + 1));
        scanf("%d", &arrayNum[i]);
    }

    // Sorting the Array
    for(int i = 0; i < size; i++) {
        minor = i;
        for(int j = i + 1; j < size; j++) {
            if(arrayNum[j] < arrayNum[minor]) {
                minor = j;
            }
        }
        temp = arrayNum[i];
        arrayNum[i] = arrayNum[minor];
        arrayNum[minor] = temp;
    }

    // Removing Duplicate Elements
    for(int i = 0; i < size; i++) {
        if(arrayNum[i] != arrayNum[i+1]) {
            newArray[count] = arrayNum[i];
            count++;
        }
    }
    
    // Data Output
    printf("\n*** UNION BETWEEN A AND B ***\n\n");
    for(int i = 0; i < count; i++) {
        printf("newArray[%d]: %d\n", i, newArray[i]);
    }

    return 0;

}