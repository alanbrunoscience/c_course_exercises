#include <stdio.h>

int main(){

    float salary, newSalary;
    
    printf("Enter the salary ($), please:\n");
    scanf("%f", &salary);

    newSalary = (salary * 1.05) * 0.93;

    printf("The new salary is $ %.2f.\n", newSalary);
    
    return 0;

}