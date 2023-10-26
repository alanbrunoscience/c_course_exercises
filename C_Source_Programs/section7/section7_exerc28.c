#include <stdio.h>
#include <math.h>

int main() {

    int numbers[10], size = sizeof(numbers) / sizeof(numbers[0]), sumNum = 0;
    float average, sumSD = 0, standardDev;

    for(int i = 0; i < size; i++) {
        printf("Enter the %dº integer number (numbers[%d]), please: ", (i+1), i);
        scanf("%d", &numbers[i]);
        sumNum += numbers[i];
    }

    // First step (Average)
    average = (float) sumNum / (float) size;

    // Calculate |x - u|² and sumSD
    for(int i = 0; i < size; i++) {
        sumSD += (pow((numbers[i] - average), 2));
    }

    // Calculate the Standard Deviation
    standardDev = sqrt(sumSD / (float) size);

    // Data Output
    printf("\nThe Standard Deviation is %.2f.\n", standardDev);

    return 0;

}