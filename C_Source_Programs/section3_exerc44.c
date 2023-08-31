#include <stdio.h>
#include <math.h>

int main(){

    float heightStep, height, amountSteps;

    printf("Enter the height (cm) of the step, please:\n");
    scanf("%f", &heightStep);

    printf("Enter the height (m) that you want to climb, please:\n");
    scanf("%f", &height);

    amountSteps = (height * 100.0) / heightStep;

    printf("You need to climb at least %.0f steps to reach %.2f m.\n", ceil(amountSteps), height);

    return 0;

}