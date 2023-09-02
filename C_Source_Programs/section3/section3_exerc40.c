#include <stdio.h>

int main(){

    int numberOfDays;
    float salary;

    printf("Enter the number of days worked, please:\n");
    scanf("%d", &numberOfDays);

    salary = (numberOfDays * 30.00) * 0.92; 

    printf("The salary is $ %.2f.\n", salary);

    return 0;

}