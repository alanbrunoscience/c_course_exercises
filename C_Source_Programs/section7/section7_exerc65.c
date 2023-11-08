#include <stdio.h>

int main() {

    int array2DA[3][3], array2DB[3][3], array2DC[3][3] = {0}, size = sizeof(array2DA) / sizeof(array2DA[0]);

    printf("*** ARRAY A ***\n\n");
    printf("Fill in the elements' values of the positions below:\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("array2DA[%d][%d]: ", i, j);
            scanf("%d", &array2DA[i][j]);
        }
    }

    printf("\n*** ARRAY B ***\n\n");
    printf("Fill in the elements' values of the positions below:\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("array2DB[%d][%d]: ", i, j);
            scanf("%d", &array2DB[i][j]);
        }
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                array2DC[i][j] += (array2DA[i][k] * array2DB[k][j]);
            }
        }
    }

    printf("\n*** ARRAY C ***\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", array2DC[i][j]);
        }
        printf("\n");
    }

    return 0;

}