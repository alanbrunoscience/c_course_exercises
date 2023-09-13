#include <stdio.h>

int main() {

    float currentSalary, adjustedSalary, finalSalary;
    int serviceTime;

    printf("Enter the current salary, please:\n");
    scanf("%f", &currentSalary);

    printf("Enter the service time (years worked), please:\n");
    scanf("%d", &serviceTime);

    // Calculating reajusted salary
    if(currentSalary <= 500.00){
        adjustedSalary = currentSalary * 1.25;
        printf("The adjusted salary with 25%% is $%.2f\n", adjustedSalary);
    } else if(currentSalary > 500.00 && currentSalary <= 1000.00) {
        adjustedSalary = currentSalary * 1.20;
        printf("The adjusted salary with 20%% is $%.2f\n", adjustedSalary);
    } else if(currentSalary > 1000.00 && currentSalary <= 1500.00) {
        adjustedSalary = currentSalary * 1.15;
        printf("The adjusted salary with 15%% is $%.2f\n", adjustedSalary);
    } else if(currentSalary > 1500.00 && currentSalary <= 2000.00) {
        adjustedSalary = currentSalary * 1.10;
        printf("The adjusted salary with 10%% is $%.2f\n", adjustedSalary);
    } else {
        adjustedSalary = currentSalary;
        printf("For a salary over $ 2000.00, there is no adjustment. So, the adjusted salary is $%.2f\n", adjustedSalary);
    }

    // Calculating salary with bonus
    if(serviceTime < 1){
        printf("There is no bonus to service time lower than 1 year. So, the salary with bonus is $%.2f\n", adjustedSalary);
    } else if(serviceTime >= 1 && serviceTime <= 3) {
        finalSalary = adjustedSalary + 100.00;
        printf("The final salary with bonus of $ 100.00 is $%.2f\n", finalSalary);
    } else if(serviceTime > 3 && serviceTime <= 6) {
        finalSalary = adjustedSalary + 200.00;
        printf("The final salary with bonus of $ 200.00 is $%.2f\n", finalSalary);
    } else if(serviceTime > 6 && serviceTime <= 10) {
        finalSalary = adjustedSalary + 300.00;
        printf("The final salary with bonus of $ 300.00 is $%.2f\n", finalSalary);
    } else {
        finalSalary = adjustedSalary + 500.00;
        printf("The final salary with bonus of $ 500.00 is $%.2f\n", finalSalary);
    }

    return 0;

}