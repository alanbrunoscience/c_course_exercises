#include <stdio.h>
#include <ctype.h>

int main() {

    typedef struct student_score {
        int regNumber;
        char answers[10];
        float grade;
    } student_score;

    student_score students[3];
    
    int size = sizeof(students) / sizeof(students[0]), countScore = 0;

    char answerSheet[10], upperC;

    printf("*** ANSWER SHEET ***\n\n");
    for(int i = 0; i < 10; i++) {
        printf("-> Q%d: ", (i+1));
        scanf(" %c", &answerSheet[i]);

        upperC = toupper(answerSheet[i]);

        while(upperC != 'A' && upperC != 'B' && upperC != 'C' && upperC != 'D' && upperC != 'E') {
            printf("\n*** The informed value is not valid. The value must be 'a', 'b', 'c', 'd', or 'e'. So, enter a new value again! ***\n\n");
            printf("-> Q%d: ", (i+1));
            scanf(" %c", &answerSheet[i]);
            upperC = toupper(answerSheet[i]);
        }
    }

    printf("\n*** STUDENTS' DATA ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("%dº STUDENT:\n\n", (i + 1));
        printf("-> Enter the student's registration number, please: ");
        scanf("%d", &students[i].regNumber);
        printf("\n*** STUDENTS' ANSWERS ***\n\n");
        for(int j = 0; j < 10; j++) {
            printf("-> Q%d: ", (j+1));
            scanf(" %c", &students[i].answers[j]);

            upperC = toupper(students[i].answers[j]);
            
            while(upperC != 'A' && upperC != 'B' && upperC != 'C' && upperC != 'D' && upperC != 'E') {
                printf("\n*** The informed value is not valid. The value must be 'a', 'b', 'c', 'd', or 'e'. So, enter a new value again! ***\n\n");
                printf("-> Q%d: ", (i+1));
                scanf(" %c", &students[i].answers[j]);
                upperC = toupper(students[i].answers[j]);
            }
        }
        printf("\n");
    }

    // Score Validation
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < 10; j++) {
            if(students[i].answers[j] == answerSheet[j]) {
                countScore++;
            }
        }
        students[i].grade = countScore;
        countScore = 0;
    }

    // Data Output
    printf("\n*** OVERALL SCORE ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("%dº STUDENT:\n\n", (i+1));
        printf("-> Registration Number: %d\n", students[i].regNumber);
        printf("-> Answers: ");
        for(int j = 0; j < 10; j++) {
            printf("%c ", students[i].answers[j]);
        }
        printf("\n-> Student Score: %.2f\n", students[i].grade);
        if(students[i].grade >= 7.0) {
            printf("-> Status: Approved\n");
        } else {
           printf("-> Status: Reproved\n");
        }
        printf("\n");
    }

    return 0;

}