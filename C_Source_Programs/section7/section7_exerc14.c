#include <stdio.h>

int main() {
    int vetNum[10], equalNumbers[10], i, minor, temp, count = 0;

    for(i = 0; i < 10; i++) {
        printf("Enter the %dº number, please: ", (i+1));
        scanf("%d", &vetNum[i]);
    }

    for(i = 0; i < 10; i++) {
        minor = i;
        for(int j = i + 1; j < 10; j++) {
            if(vetNum[j] < vetNum[minor]) {
                minor = j;
            }
        }
        temp = vetNum[i];
        vetNum[i] = vetNum[minor];
        vetNum[minor] = temp;
    }

    for(i = 0; i < 10; i++) {
        if(vetNum[i] == vetNum[i+1]) {
            equalNumbers[count] = vetNum[i];
            count++;
        }
    }

    printf("\n*** EQUAL NUMBERS ***\n\n");
    printf("-> The equal numbers on the 'equalNumbers' array are: ");

    for(i = 0; i < count; i++) {
        printf("%d ", equalNumbers[i]);
    }

    printf("\n");

    return 0;
}
