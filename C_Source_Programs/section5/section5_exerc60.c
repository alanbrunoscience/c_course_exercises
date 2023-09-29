#include <stdio.h>

int main () {

    int num, i = 0, sumNumbers = 0, sumEven = 0, countEven = 0, major = 0, minor = 0;

    printf("Enter the %dº number, please:\n", (i+1));
    scanf("%d", &num);

    if(num == 0){
        printf("Finishing the program...\n");
        return 1;
    }

    major = num;
    minor = num;

    if(num % 2 == 0 && num != 0) {
        sumEven += num;
        countEven++;
    }

    sumNumbers += num;

    i++;

    do {
        
        printf("Enter the %dº number, please:\n", (i+1));
        scanf("%d", &num);

        sumNumbers += num;

        if(major < num && num != 0) {
            major = num;
        }

        if(minor > num && num != 0) {
            minor = num;
        }

        if(num % 2 == 0 && num != 0) {
            sumEven += num;
            countEven++;
        }

        i++;

    } while(num != 0);

    printf("\n*** FINAL RESULT ***\n");
    printf("-> Sum of numbers entered: %d;\n", sumNumbers);
    printf("-> Number of numbers entered (without considering 0, to end the program): %d;\n", (i - 1));
    printf("-> The average of numbers entered (without considering 0, to end the program): %.2f;\n", ((float)sumNumbers / (float)(i - 1)));
    printf("-> The greater number entered (without considering 0, to end the program): %d;\n", major);
    printf("-> The smaller number entered (without considering 0, to end the program): %d;\n", minor);
    printf("-> The average of even numbers entered (without considering 0, to end the program): %.2f;\n", ((float)sumEven / (float) countEven));

    return 0;

}