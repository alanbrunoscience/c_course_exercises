#include <stdio.h>

int main() {

    int array2D[3][6], size = sizeof(array2D[0]) / sizeof(array2D[0][0]), sumOdd = 0, sum24 = 0, sum12 = 0, countElem = 0;

    printf("Fill in the elements' value from the positions below:\n\n");
    for(int i = 0; i < size / 2; i++) {
        for(int j = 0; j < size; j++) {
            printf("array2D[%d][%d]: ", i, j);
            scanf("%d", &array2D[i][j]);
        }
    }

    for(int i = 0; i < size / 2; i++) {
        for(int j = 0; j < size; j++) {
            if(j % 2 != 0) {
                sumOdd += array2D[i][j];
            }

            if(j == 1 || j == 3) {
                if(j % 2 != 0) {
                    sum24 += array2D[i][j];
                    countElem++;
                }
            }
        }
    }

    printf("\n*** FINAL RESULTS ***\n\n");
    printf("-> The sum of all elements from odd columns: %d;\n", sumOdd);
    printf("-> The arithmetic mean of the elements in the second and fourth columns: %.2f.\n", ((float)(sum24) / (float)countElem));
    printf("\n*** ORIGINAL MATRIX ***\n\n");
    for(int i = 0; i < size / 2; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", array2D[i][j]);
        }
        printf("\n");
    }

    printf("\n*** MODIFIED MATRIX ***\n\n");
    for(int i = 0; i < size / 2; i++) {
        for(int j = 0; j < size; j++) {
            if(j == 0 || j == 1) {
                sum12 += array2D[i][j];
                array2D[i][5] = sum12;
            }
            printf("%d ", array2D[i][j]);
        }
        sum12 = 0;
        printf("\n");
    }

    return 0;

}