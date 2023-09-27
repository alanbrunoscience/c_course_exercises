#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

    int option;
    float n1, n2;

    do {
        printf("*** CALCULATOR ***\n\n1) Addition;\n2) Subtraction;\n3) Multiplication;\n4) Division;\n5) Exit;\n\n-> ");
        scanf("%d", &option);

        switch (option) {
            case 1:

                system("clear");

                printf("Enter the first number, please:\n");
                scanf("%f", &n1);

                printf("Enter the second number, please:\n");
                scanf("%f", &n2);

                printf("%.2f + %.2f = %.2f\n", n1, n2, (n1 + n2));

                sleep(5);

                system("clear");

                break;
            case 2:

                system("clear");

                printf("Enter the first number, please:\n");
                scanf("%f", &n1);

                printf("Enter the second number, please:\n");
                scanf("%f", &n2);

                printf("%.2f - %.2f = %.2f\n", n1, n2, (n1 - n2));

                sleep(5);

                system("clear");

                break;
            case 3:

                system("clear");

                printf("Enter the first number, please:\n");
                scanf("%f", &n1);

                printf("Enter the second number, please:\n");
                scanf("%f", &n2);

                printf("%.2f * %.2f = %.2f\n", n1, n2, (n1 * n2));

                sleep(5);

                system("clear");

                break;
            case 4:

                system("clear");

                printf("Enter the first number, please:\n");
                scanf("%f", &n1);

                printf("Enter the second number, please:\n");
                scanf("%f", &n2);

                printf("%.2f / %.2f = %.2f\n", n1, n2, (n1 / n2));

                sleep(5);

                system("clear");

                break;
            default:
                printf("Finishing the program...\n");
                break;
        }

    } while (option != 5);

    return 0;
}