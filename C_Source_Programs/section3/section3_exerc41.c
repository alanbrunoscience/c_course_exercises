#include <stdio.h>

int main(){

    int hoursWorked;
    float priceHour, salary;

    printf("Enter the price of the worked hour in reais (R$), please:\n");
    scanf("%f", &priceHour);

    printf("Enter the number of hours worked, please:\n");
    scanf("%d", &hoursWorked);

    salary = priceHour * hoursWorked;

    printf("The salary is R$ %.2f\n", salary);

    return 0;

}