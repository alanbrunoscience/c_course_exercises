#include <stdio.h>
#include <math.h>

int main() {

    int array2D[10][10], size = sizeof(array2D) / sizeof(array2D[0]);

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(i == j) {
                printf("%d ", (int)((3 * pow(i, 2)) - 1));
            } else if(i > j) {
                printf("%d ", (int)((4 * pow(i, 3)) - (5 * pow(j, 2)) + 1));
            } else {
                printf("%d ", (2 * i) + (7 * j) - 2);
            }
        }
        printf("\n");
    }

    return 0;

}