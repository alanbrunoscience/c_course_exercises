#include <stdio.h>
#include <ctype.h> // Required to use toupper() method

int main() {

    char scoreStd[5][10], upperC, size = sizeof(scoreStd[0]) / sizeof(scoreStd[0][0]), answerSheet[size];
    int countScore = 0;

    // Data Input
    printf("*** ANSWER SHEET ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("-> Q%d: ", (i+1));
        scanf(" %c", &answerSheet[i]);

        upperC = toupper(answerSheet[i]);

        while(upperC != 'A' && upperC != 'B' && upperC != 'C' && upperC != 'D') {
            printf("\n*** The informed value is not valid. The value must be 'a', 'b', 'c', or 'd'. So, enter a new value again! ***\n\n");
            printf("-> Q%d: ", (i+1));
            scanf(" %c", &answerSheet[i]);
            upperC = toupper(answerSheet[i]);
        }
    }

    printf("\n*** STUDENTS' ANSWERS ***\n\n");
    for(int i = 0; i < (size / 2); i++) {
        printf("%dº STUDENT:\n\n", (i + 1));
        for(int j = 0; j < size; j++) {
            printf("-> Q%d: ", (j+1));
            scanf(" %c", &scoreStd[i][j]);

            upperC = toupper(scoreStd[i][j]);

            while(upperC != 'A' && upperC != 'B' && upperC != 'C' && upperC != 'D') {
                printf("\n*** The informed value is not valid. The value must be 'a', 'b', 'c', or 'd'. So, enter a new value again! ***\n\n");
                printf("-> Q%d: ", (j+1));
                scanf(" %c", &scoreStd[i][j]);
                upperC = toupper(scoreStd[i][j]);
            }

        }
        printf("\n");
    }

    // Score Validation and Data Output
    printf("\n*** OVERALL SCORE ***\n\n");
    for(int i = 0; i < (size / 2); i++) {
        for(int j = 0; j < size; j++) {
            if(scoreStd[i][j] == answerSheet[j]) {
                countScore++;
            }
        }
        printf("-> %dº Student: %d out of %d;\n", (i+1), countScore, size);
        countScore = 0;
    }

    return 0;

}