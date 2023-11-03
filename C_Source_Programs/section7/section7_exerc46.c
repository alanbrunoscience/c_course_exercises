#include <stdio.h>

int main() {

    int array2D[4][4], size = sizeof(array2D) / sizeof(array2D[0]), major = 0, iM = 0, jM = 0;

    printf("Enter the elements' value of the positions below:\n\n");
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(i == 0 & j == 0) {
                printf("array2D[%d][%d]: ", i, j);
                scanf("%d", &array2D[i][j]);
                major = array2D[i][j];
                iM = i;
                jM = j;
            } else {
                printf("array2D[%d][%d]: ", i, j);
                scanf("%d", &array2D[i][j]);
                if(major < array2D[i][j]) {
                    major = array2D[i][j];
                    iM = i;
                    jM = j;
                }
            }
        }
    }

    printf("\n\n-> The biggest element is %d and it is located in array2D[%d][%d].\n", major, iM, jM);

    return 0;

}