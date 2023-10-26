#include <stdio.h>

int main() {

    typedef struct student_data {
        int studentNum;
        float studentHeight;
    } student_data;

    // struct student_data student[5];

    student_data student[5];

    int size = sizeof(student) / sizeof(student[0]);

    for(int i = 0; i < size; i++) {
        printf("*** %dº STUDENT ***\n\n", (i+1));
        printf("Student's number: ");
        scanf("%d", &student[i].studentNum);
        printf("Student's height: ");
        scanf("%f", &student[i].studentHeight);
        printf("\n");
    }

    float majorHeight = student[0].studentHeight, minorHeight = student[0].studentHeight;
    int codeMajorStud = student[0].studentNum, codeMinorStud = student[0].studentNum;

    for(int i = 0; i < size; i++) {
        if(majorHeight < student[i].studentHeight) {
            majorHeight = student[i].studentHeight;
            codeMajorStud = student[i].studentNum;
        }

        if(minorHeight > student[i].studentHeight) {
            minorHeight = student[i].studentHeight;
            codeMinorStud = student[i].studentNum;
        }
    }

    printf("\n *** RESULT ***\n\n");
    printf("-> Student's number of the greatest height: %d\n", codeMajorStud);
    printf("-> Height: %.2f\n\n", majorHeight);
    printf("-> Student's number of the smallest height: %d\n", codeMinorStud);
    printf("-> Height: %.2f\n", minorHeight);
    
    return 0;

}