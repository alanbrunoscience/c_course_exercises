#include <stdio.h>

int main() {

    int age, currentYear, birthYear;

    printf("Enter the age, please: \n");
    scanf("%d", age);

    printf("Enter the current year, please: \n");
    scanf("%d", age);

    birthYear = currentYear - age;

    printf("The birth year is %d.", birthYear);

    return 0;

}