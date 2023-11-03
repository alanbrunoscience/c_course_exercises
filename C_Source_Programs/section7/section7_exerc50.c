#include <stdio.h>

int main() {

    int array2D[3][3], size = sizeof(array2D) / sizeof(array2D[0]), numUpDiag[size], count = 0, sumUpDiag = 0;

    printf("Enter the elements' value of the positions below:\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("-> array2D[%d][%d]: ", i, j);
            scanf("%d", &array2D[i][j]);

            if(i < j) {
                numUpDiag[count] = array2D[i][j];
                sumUpDiag += array2D[i][j];
                count++;
            }
        }
    }

    printf("\nThe elements above the main diagonal and their sum:\n\n-> ");

    for(int i = 0; i < size; i++) {
        printf("%d ", numUpDiag[i]);
    }

    printf("\n-> Sum: %d\n", sumUpDiag);

    return 0;

}