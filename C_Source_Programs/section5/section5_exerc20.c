#include <stdio.h>

int main() {

    int num, numCounter = 0, evenCounter = 0;

    do {

        printf("Enter an integer number, please. If you type 1000, the data input will stop:\n");
        scanf("%d", &num);

        numCounter++;

        if(num % 2 == 0) {
            printf("\nThis number is even.\n\n");
            evenCounter++;
        } else {
            printf("\nThis is not an even number.\n\n");
        }

    } while(num != 1000);

    printf("*** DATA READ ***\n");
    printf("-> Numbers read: %d;\n", numCounter);
    printf("-> Even numbers read: %d;\n", evenCounter);

    return 0;

}