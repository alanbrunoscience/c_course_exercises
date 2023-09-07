#include <stdio.h>

int main ()
{
    int age, yearsWorked;

    printf("Enter the age, please:\n");
    scanf("%d", &age);

    printf("Enter the years worked, please:\n");
    scanf("%d", &yearsWorked);

    while(yearsWorked >= age){

        printf("\n*** It's impossible that the years worked is greater or equal than age. The years worked have to smaller than age. Enter this information again. ***\n\n");

        printf("Enter the age, please:\n");
        scanf("%d", &age);

        printf("Enter the years worked, please:\n");
        scanf("%d", &yearsWorked);

    }

    if (age >= 65 || yearsWorked >= 30 || age >= 60 && yearsWorked >= 25) {
        printf("\nRetirement granted.\n");
    } else {
        printf("\nThis worker doesn't meet the requirements to retire.\n");
    }

    return 0;

}