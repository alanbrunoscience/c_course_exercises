#include <stdio.h>

int main() {

    int qtyNum, major = 0, countNum = 0, numOfIncidents;

    printf("Enter the quantity of numbers to be read, please:\n");
    scanf("%d", &qtyNum);

    int numbers[qtyNum];

    for(int i = 0; i < qtyNum; i++) {

        printf("Enter the %dº number, please:\n", (i+1));
        scanf("%d", &numbers[i]);

        if(major < numbers[i]) {
            major = numbers[i];
        }

    }

    for(int i = 0; i < qtyNum; i++) {
        if(major == numbers[i]){
            countNum++;
        }
    }

    printf("Number %d is the biggest on the list and has appeared %d times.\n", major, countNum);

    return 0;
    
}