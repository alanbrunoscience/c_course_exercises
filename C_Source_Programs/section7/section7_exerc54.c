#include <stdio.h>
#include <stdlib.h>

int main() {

    int array2D[5][5], size = sizeof(array2D) / sizeof(array2D[0]);

    for(int i = 0; i < size; i++) {
        for(int j = (size - 1); j >= 0; j--) {
            if(abs(i - j) < 1) {
                printf("1 ");
            }
            else {
                printf("0 "); 
            }
        }
        printf("\n");
    }
    
    return 0;

}