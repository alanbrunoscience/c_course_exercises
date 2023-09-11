#include <stdio.h>

int main() {
    float grade;
    int numAbsences;

    printf("Enter the grade, please:\n");
    scanf("%f", &grade);

    printf("Enter the number of absences, please:\n");
    scanf("%d", &numAbsences);

    if (grade >= 9.0 && grade <= 10.0) {
        if (numAbsences <= 20) {
            printf("-> CONCEPT: A\n");
        } else {
            printf("-> CONCEPT: B\n");
        }
    } else if (grade >= 7.5 && grade < 9.0) {
        if (numAbsences <= 20) {
            printf("-> CONCEPT: B\n");
        } else {
            printf("-> CONCEPT: C\n");
        }
    } else if (grade >= 5.0 && grade < 7.5) {
        if (numAbsences <= 20) {
            printf("-> CONCEPT: C\n");
        } else {
            printf("-> CONCEPT: D\n");
        }
    } else if (grade >= 4.0 && grade < 5.0) {
        if (numAbsences <= 20) {
            printf("-> CONCEPT: D\n");
        } else {
            printf("-> CONCEPT: E\n");
        }
    } else if (grade >= 0.0 && grade < 4.0) {
        printf("-> CONCEPT: E\n");
    } else {
        printf("Invalid grade entered.\n");
    }

    return 0;
}