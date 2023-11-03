#include <stdio.h>

int main() {

    int array2D[3][3], size = sizeof(array2D) / sizeof(array2D[0]), numDownDiag[size], count = 0, sumDownDiag = 0;

    printf("Enter the elements' value of the positions below:\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("-> array2D[%d][%d]: ", i, j);
            scanf("%d", &array2D[i][j]);

            if(i > j) {
                numDownDiag[count] = array2D[i][j];
                sumDownDiag += array2D[i][j];
                count++;
            }
        }
    }

    printf("\nThe elements below the main diagonal and their sum:\n\n-> ");

    for(int i = 0; i < size; i++) {
        printf("%d ", numDownDiag[i]);
    }

    printf("\n-> Sum: %d\n", sumDownDiag);

    return 0;

}