#include <stdio.h>

int main() {

    int array2DA[4][4], array2DB[4][4], array2DC[4][4], size = sizeof(array2DA) / sizeof(array2DA[0]);

    printf("*** ARRAY 2D A ***\n\n");
    printf("Enter the value of the elements for each position below:\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("-> array2DA[%d][%d]: ", i, j);
            scanf("%d", &array2DA[i][j]);
        }
    }

    printf("\n\n*** ARRAY 2D B ***\n\n");
    printf("Enter the value of the elements for each position below:\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("-> array2DB[%d][%d]: ", i, j);
            scanf("%d", &array2DB[i][j]);
        }
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(array2DA[i][j] > array2DB[i][j]) {
                array2DC[i][j] = array2DA[i][j];
            } else {
                array2DC[i][j] = array2DB[i][j];
            }
        }
    }

    printf("\n\n*** ARRAY 2D C ***\n\n");
    printf("Only the largest elements of each position of the matrix A or B.\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", array2DC[i][j]);
        }
        printf("\n");
    }

    return 0;

}
