#include <stdio.h>

int main() {

    int array2D[3][3], size = sizeof(array2D) / sizeof(array2D[0]), transpArray[3][3];

    printf("Enter the elements' value of the positions below:\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("-> array2D[%d][%d]: ", i, j);
            scanf("%d", &array2D[i][j]);
        }
    }

    for(int i = (size - 1); i >= 0; i--) {
        for(int j = 0; j < size; j++) {
            transpArray[j][i] = array2D[i][j];
        }
    }

    printf("\n*** ORIGINAL MATRIX ***\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", array2D[i][j]);
        }
        printf("\n");
    }

    printf("\n*** TRANSPOSED MATRIX ***\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", transpArray[i][j]);
        }
        printf("\n");
    }

    return 0;

}