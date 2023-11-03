#include <stdio.h>
#include <stdlib.h>

int main() {

    int array2D[5][5], size = sizeof(array2D) / sizeof(array2D[0]);

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if((i + j) == (size - 1)) {
                array2D[i][j] = 1;
            }
            else {
                array2D[i][j] = 0;
            }
        }
    }

    // Print the resulting 2D array
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", array2D[i][j]);
        }
        printf("\n");
    }

    return 0;
}
