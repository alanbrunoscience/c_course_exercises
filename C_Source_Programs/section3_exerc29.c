#include <stdio.h>

int main(){

    int i = 0;
    float grade, sum = 0, average;

    while(i < 4){

        printf("Enter the %dº grade, please:\n", (i+1));
        scanf("%f", &grade);

        sum += grade;

        i++;

    }

    average = sum / i;

    printf("The average of all grades is %.2f\n", average);

    return 0;

}