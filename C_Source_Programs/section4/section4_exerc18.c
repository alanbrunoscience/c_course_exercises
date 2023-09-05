#include <stdio.h>

int main() {

    int option;
    float n1, n2;

    printf("*** CALCULATOR ***\n\nChoose an option (1, 2, 3 or 4):\n\n1 - Addition (+);\n2 - Subtraction (-);\n3 - Division (/);\n4 - Multiplication (*).\n\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("\nEnter the first value, please:\n");
        scanf("%f", &n1);
        printf("Enter the second value, please:\n");
        scanf("%f", &n2);
        printf("%.2f + %.2f = %.2f\n", n1, n2, (n1 + n2));
        break;
    case 2:
        printf("\nEnter the first value, please:\n");
        scanf("%f", &n1);
        printf("Enter the second value, please:\n");
        scanf("%f", &n2);
        printf("%.2f - %.2f = %.2f\n", n1, n2, (n1 - n2));
        break;
    case 3:
        printf("\nEnter the first value, please:\n");
        scanf("%f", &n1);
        printf("Enter the second value, please:\n");
        scanf("%f", &n2);
        printf("%.2f / %.2f = %.2f\n", n1, n2, (n1 / n2));
        break;
    case 4:
        printf("\nEnter the first value, please:\n");
        scanf("%f", &n1);
        printf("Enter the second value, please:\n");
        scanf("%f", &n2);
        printf("%.2f * %.2f = %.2f\n", n1, n2, (n1 * n2));
        break;
    default:
        printf("\nInvalid option!\n");
        break;
    }

    return 0;

}