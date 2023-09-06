#include <stdio.h>

int main(){

    int option;
    float n1, n2;

    printf("*** CALCULATOR ***\n\nChoose an option (1, 2, 3 or 4):\n\n1 - Sum of two numbers (+);\n2 - Difference of two numbers (greater by smaller) (-);\n3 - Product between two numbers (*);\n4 - Division between two numbers (denominator cannot be zero) (/).\n\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:

        printf("\nEnter the first value, please:\n");
        scanf("%f", &n1);

        printf("Enter the second value, please:\n");
        scanf("%f", &n2);

        printf("\n%.2f + %.2f = %.2f\n", n1, n2, (n1 + n2));

        break;

    case 2:

        printf("\nEnter the first value, please:\n");
        scanf("%f", &n1);

        printf("Enter the second value, please:\n");
        scanf("%f", &n2);

        if(n1 > n2){
            printf("\n%.2f - %.2f = %.2f\n", n1, n2, (n1 - n2));
        } else {
            printf("\n%.2f - %.2f = %.2f\n", n2, n1, (n2 - n1));
        }
        
        break;

    case 3:

        printf("\nEnter the first value, please:\n");
        scanf("%f", &n1);

        printf("Enter the second value, please:\n");
        scanf("%f", &n2);

        printf("\n%.2f * %.2f = %.2f\n", n1, n2, (n1 * n2));

        break;

    case 4:

        printf("\nEnter the numerator value, please:\n");
        scanf("%f", &n1);

        printf("Enter the denominator value, please:\n");
        scanf("%f", &n2);

        if (n2 == 0){
            printf("\n*** The denominator mustn't be zero. Enter another value, please! ***\n");

            do {
                printf("\nEnter the denominator value, please (the denominator mustn't be zero):\n");
                scanf("%f", &n2);
            } while (n2 == 0);

            printf("\n%.2f / %.2f = %.2f\n", n1, n2, (n1 / n2));

        } else {
            printf("\n%.2f / %.2f = %.2f\n", n1, n2, (n1 / n2));
        }

        break;

    default:
        
        printf("\nInvalid option!\n");
        
        break;

    }

    return 0;

}