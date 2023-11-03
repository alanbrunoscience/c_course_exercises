#include <stdio.h>

int main() {

    int array2D[3][3], size = sizeof(array2D) / sizeof(array2D[0]), n, bool = 0;

    printf("Enter the elements' value in the positions below:\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("array2D[%d][%d]: ", i, j);
            scanf("%d", &array2D[i][j]);
        }
    }

    printf("\nEnter an aleatory integer value, please: ");
    scanf("%d", &n);

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(n == array2D[i][j]) {
                printf("\nThe entered value was found in the position array2D[%d][%d]. So array2D[%d][%d] is equal to %d.\n", i, j, i, j, array2D[i][j]);
                bool = 1;
            }
        }
    }

    if(bool == 0) {
        printf("\nThe value %d is not on the two-dimensional array.\n", n);
    }

    return 0;

}