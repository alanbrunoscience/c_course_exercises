#include <stdio.h>

int main() {

    int age, currentYear, birthYear;

    printf("Enter the age, please: \n");
    scanf("%d", &age);

    printf("Enter the current year, please: \n");
    scanf("%d", &currentYear);

    birthYear = currentYear - age;

    printf("The birth year is %d.\n", birthYear);

    return 0;

}