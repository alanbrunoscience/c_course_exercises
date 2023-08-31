#include <stdio.h>
#include <stdlib.h>

int main(){

    int *digits = NULL, numDigits;
    char input[100];

    do {
        numDigits = 0;
        printf("Enter an integer with a maximum of 3 digits (from 100 to 999):\n");
        fgets(input, sizeof(input), stdin);

        for(int i = 0; input[i] != '\0'; i++) {
            if(input[i] >= '0' && input[i] <= '9') {
                numDigits++;
            }
        }

        if (numDigits != 3 || input[0] == '0') {
            printf("\n*** This is not a valid entry. The entry must be a 3-digit integer (from 100 to 999) ***\n\n");
        }

    } while(numDigits != 3 || input[0] == '0');

    // Allocate memory for the dynamic array
    digits = (int *)malloc(numDigits * sizeof(int));

    // Populate the dynamic array with the digits
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
           digits[i] = input[i] - '0';
        }
    }

    for (int i = (numDigits - 1); i >= 0; i--) {
        printf("%d", digits[i]);
    }

    printf("\n");

    // Clean up: free the dynamically allocated memory
    free(digits);

    return 0;

}