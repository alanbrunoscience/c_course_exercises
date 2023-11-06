#include <stdio.h>

int main() {

    float grades[10][3], minorGrade;
    int sizeI = sizeof(grades) / sizeof(grades[0]), sizeJ = sizeof(grades[0]) / sizeof(grades[0][0]), count1 = 0, count2 = 0, count3 = 0, numberTest;

    for(int i = 0; i < sizeI; i++) {
        printf("*** %dº STUDENT ***\n\nGRADES:\n\n", (i+1));
        for(int j = 0; j < sizeJ; j++) {
            printf("Enter the grade of the %dº test, please: ", (j+1));
            scanf("%f", &grades[i][j]);

            while(grades[i][j] < 0 || grades[i][j] > 10) {
                printf("\n*** The test grade is invalid. Must be greater than or equal to zero or less than or equal to 10. Enter a new valid grade, please! ***\n\n");
                printf("Enter the grade of the %dº test, please: ", (j+1));
                scanf("%f", &grades[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n*** GRADE REPORT BY STUDENT ***\n\n");
    for(int i = 0; i < sizeI; i++) {
        minorGrade = 10;
        numberTest = 0;
        printf("*** %dº STUDENT ***\n\nGRADES:\n\n", (i+1));
        for(int j = 0; j < sizeJ; j++) {
            printf("-> Test Score %d: %.2f\n", (j+1), grades[i][j]);

            if(minorGrade > grades[i][j]) {
                minorGrade = grades[i][j];
                numberTest = j+1;
            }
        }
        printf("-> Smallest Grade (Test %d): %.2f\n", numberTest, minorGrade);
        
        if((numberTest - 1) == 0) {
            count1++;
        } else if((numberTest - 1) == 1) {
            count2++;
        } else {
            count3++;
        }

        printf("\n");

    }
    printf("\n*** REPORT OF LOWEST GRADES BY NUMBER OF STUDENTS ***\n\n");
    printf("-> Number of students who received the lowest grade in test 1: %d\n", count1);
    printf("-> Number of students who received the lowest grade in test 2: %d\n", count2);
    printf("-> Number of students who received the lowest grade in test 3: %d\n", count3);
    
    return 0;

}