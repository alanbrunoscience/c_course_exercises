#include <stdio.h>

int main() {

    int array2D[4][4], size = sizeof(array2D) / sizeof(array2D[0]);

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", (i * j));
        }
        printf("\n");
    }

    return 0;

}