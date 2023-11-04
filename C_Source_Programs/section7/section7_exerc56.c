#include <stdio.h>

int main() {

    int array2DA[4][4], array2DB[4][4], size = sizeof(array2DA) / sizeof(array2DA[0]);

    printf("Enter the value of the elements for the positions below. Elements must be between 1 and 20 (including):\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("array2DA[%d][%d]: ", i, j);
            scanf("%d", &array2DA[i][j]);

            while(array2DA[i][j] < 1 || array2DA[i][j] > 20) {
                printf("\n*** Number invalid! The number must be between 1 and 20. Insert the array2DA[%d][%d] value again ***\n\n", i, j);
                printf("array2DA[%d][%d]: ", i, j);
                scanf("%d", &array2DA[i][j]);
            }
        }
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(i < j) {
                array2DB[i][j] = 0;
            } else {
                array2DB[i][j] = array2DA[i][j];
            }
        }
    }

    printf("\n*** ORIGINAL MATRIX ***\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", array2DA[i][j]);
        }
        printf("\n");
    }

    printf("\n*** TRANSFORMED MATRIX ***\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", array2DB[i][j]);
        }
        printf("\n");
    }

    return 0;

}