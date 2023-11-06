#include <stdio.h>

int main() {

    int array2D[3][3], size = sizeof(array2D) / sizeof(array2D[0]), array1D[size], sumElements = 0;

    printf("Fill in the elements' value from the positions below:\n\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("array2D[%d][%d]: ", j, i);
            scanf("%d", &array2D[j][i]);

            sumElements += array2D[j][i];

            array1D[i] = sumElements;
        }
        sumElements = 0;
    }

    printf("\n*** SUM OF COLUMNS ELEMENTS ***\n\n");
    for(int i = 0; i < size; i++){
        printf("array1D[%d]: %d\n", i, array1D[i]);
    }

    return 0;

}