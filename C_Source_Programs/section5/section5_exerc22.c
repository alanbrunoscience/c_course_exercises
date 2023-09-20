#include <stdio.h>

int main()
{

    float grade, sumGrades = 0, countGrades = 0;

    printf("Enter the grade between 10 and 20, please. Otherwise, the program will be finished:\n");
    scanf("%f", &grade);

    while (grade >= 10.0 && grade <= 20.0){
        sumGrades += grade;
        countGrades++;
        printf("Enter the grade between 10 and 20, please. Otherwise, the program will be finished:\n");
        scanf("%f", &grade);
    }

    if(sumGrades == 0.0) {
        printf("The average of the grades inserted is 0.0.\n");
    } else {
        printf("The average of the grades inserted is %.2f.\n", (sumGrades / countGrades));
    }

    return 0;
}