#include <stdio.h>

int main() {

    float numbers[10], sumPosNum = 0;
    int size = sizeof(numbers) / sizeof(numbers[0]), countNegNum = 0;

    for(int i = 0; i < size; i++) {
        printf("Enter the %dº real number (numbers[%d]), please: ", (i+1), i);
        scanf("%f", &numbers[i]);

        if(numbers[i] >= 0) {
            sumPosNum += numbers[i];
        } else {
            countNegNum++;
        }
    }

    printf("\nThe quantity of negative numbers is %d, and the sum of all integer numbers is %.2f.\n", countNegNum, sumPosNum);

    return 0;

}