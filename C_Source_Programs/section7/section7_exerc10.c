#include <stdio.h>

int main() {

    float grades[5], sumGrades = 0, average = 0;
    int size = sizeof(grades) / sizeof(grades[0]);

    for(int i = 0; i < size; i++) {
        printf("Enter the %dº grade (grades[%d]) between 0 and 10 (including), please: ", (i + 1), i);
        scanf("%f", &grades[i]);

        while(grades[i] < 0 || grades[i] > 10) {
            printf("The grade is invalid! It needs to be between 0 and 10 (including). Enter the %dº grade (grades[%d]), again: ", (i + 1), i);
            scanf("%f", &grades[i]);
        }

        sumGrades += grades[i];

    }

    average = sumGrades / size;

    printf("The grade average is %.2f.\n", average);

    return 0;

}