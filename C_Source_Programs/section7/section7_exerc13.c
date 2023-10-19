#include <stdio.h>

int main() {

    int numbers[5], major, largNumPos, minor, smallestNumPos;

    printf("Enter the 1º value (numbers[0]), please: ");
    scanf("%d", &numbers[0]);
    
    major = numbers[0];
    largNumPos = 0;

    minor = numbers[0];
    smallestNumPos = 0;

    for(int i = 1; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        printf("Enter the %dº value (numbers[%d]), please: ", (i+1), i);
        scanf("%d", &numbers[i]);

        if(major < numbers[i]){
            major = numbers[i];
            largNumPos = i;
        }

        if(minor > numbers[i]) {
            minor = numbers[i];
            smallestNumPos = i;
        }

    }

    printf("\n*** RESULTS ***\n\n");
    printf("-> Largest number: %d / Position: %d;\n", major, largNumPos);
    printf("-> Smallest number: %d / Position: %d.\n", minor, smallestNumPos);

    return 0;

}