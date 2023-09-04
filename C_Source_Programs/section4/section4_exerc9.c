#include <stdio.h>

int main(){

    float salary, instAmnt;

    printf("Enter the salary, please:\n");
    scanf("%f", &salary);

    printf("Enter the loan installment amount:\n");
    scanf("%f", &instAmnt);

    if(instAmnt > (salary * 0.20))
        printf("Loan not granted.\n");
    else
        printf("Loan granted.\n");

    return 0;

}