#include <stdio.h>
#include <stdlib.h>

int main() {

    int array2D[5][5], size = sizeof(array2D) / sizeof(array2D[0]), numbersDiag[size], count = 0, sumDiag = 0;

    printf("Enter the elements' value of the positions below:\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("-> array2D[%d][%d]: ", i, j);
            scanf("%d", &array2D[i][j]);

            if((i + j) == (size - 1)) {
                numbersDiag[count] = array2D[i][j];
                sumDiag += array2D[i][j];
                count++;
            }

        }
    }

    printf("\nThe elements of the secondary diagonal and their sum:\n\n-> ");
    
    for(int i = 0; i < size; i++) {
        printf("%d ", numbersDiag[i]);
    }

    printf("\n-> Sum: %d\n", sumDiag);

    return 0;
}
