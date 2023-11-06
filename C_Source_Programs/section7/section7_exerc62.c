#include <stdio.h>

int main() {

    int array2D[5][4], size = sizeof(array2D) / sizeof(array2D[0]), testsAverage = 0, worksAverage = 0, major, rnMajor = 0, sumGrades = 0;

    printf("*** STUDENT DATA ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("%dº STUDENT ***\n\n", (i+1));
        for(int j = 0; j < (size - 1); j++) {
            if(j == 0) {
                printf("-> Registration Number: ");
                scanf("%d", &array2D[i][j]);
            } else if (j == 1) {
                printf("-> Tests Average: ");
                scanf("%d", &array2D[i][j]);

                while(array2D[i][j] < 0 || array2D[i][j] > 10) {
                    printf("\n*** The test average is invalid. Must be greater than or equal to zero or less than or equal to 10. Enter a new valid tests average value, please! ***\n\n");
                    printf("-> Tests Average: ");
                    scanf("%d", &array2D[i][j]);
                }

                testsAverage = array2D[i][j];

            } else if (j == 2) {
                printf("-> Average School Work: ");
                scanf("%d", &array2D[i][j]);
                

                while(array2D[i][j] < 0 || array2D[i][j] > 10) {
                    printf("\n*** The average school work is invalid. Must be greater than or equal to zero or less than or equal to 10. Enter a new valid average school work value, please! ***\n\n");
                    printf("-> Average School Work: ");
                    scanf("%d", &array2D[i][j]);
                }

                worksAverage = array2D[i][j];

            } else if(j == 3) {
                printf("-> Final Grade (Tests Average + Average School Work): %d\n", (testsAverage + worksAverage));
                sumGrades += (testsAverage + worksAverage);
                if(major < (testsAverage + worksAverage)) {
                    major = (testsAverage + worksAverage);
                    rnMajor = array2D[i][0];
                }
            }
            
        }
        printf("\n");
    }

    printf("\n*** FINAL RESULT ***\n\n");
    printf("-> The registration number of the student who obtained the highest final grade is: %d (Final Grade: %d)\n", rnMajor, major);
    printf("-> Final grades arithmetics average: %.2f\n", ((float) sumGrades / (float) size));

    return 0;

}