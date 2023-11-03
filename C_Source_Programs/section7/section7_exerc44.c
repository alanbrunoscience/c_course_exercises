#include <stdio.h>

int main() {

    int array2D[5][5], size = sizeof(array2D) / sizeof(array2D[0]);
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++) {
            if(i == j) {
                printf("1 ");
            } else {
                printf("0 ");
            }    
        }
        printf("\n");
    }

    return 0;

}