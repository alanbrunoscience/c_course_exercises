#include <stdio.h>

int main() {

    int array2D[5][4], size = sizeof(array2D) / sizeof(array2D[0]), j, finalGrade, major = 0, rnMajor = 0, sumGrades = 0;

    printf("*** STUDENT DATA ***\n\n");
    for(int i = 0; i < size; i++) {
        finalGrade = 0;
        j = 0;
        printf("%dº STUDENT ***\n\n", (i+1));
        printf("-> Registration Number: ");
        scanf("%d", &array2D[i][j]);
        printf("-> Tests Average: ");
        for(j = 1; j < (size - 2); j++) {
            scanf("%d", &array2D[i][j]);

            while(array2D[i][j] < 0 || array2D[i][j] > 10) {
                printf("\n*** The previous value is invalid. It must be greater than or equal to zero or less than or equal to 10. Enter a new valid value, please! ***\n-> ");
                scanf("%d", &array2D[i][j]);
                printf("\n");
            }

            if(j < (size - 3)) {
                printf("-> Average School Work: ");
            } else {
                printf("-> Final Grade (Tests Average + Average School Work): ");
            }
            finalGrade += array2D[i][j];
        }
        printf("%d\n", finalGrade);
        sumGrades += finalGrade;
        if(major < finalGrade) {
            major = finalGrade;
            rnMajor = array2D[i][0];
        }
        printf("\n");
    }

    printf("\n*** FINAL RESULT ***\n\n");
    printf("-> The registration number of the student who obtained the highest final grade is: %d (Final Grade: %d)\n", rnMajor, major);
    printf("-> Final grades arithmetics average: %.2f\n", ((float) sumGrades / (float) size));

    return 0;

}