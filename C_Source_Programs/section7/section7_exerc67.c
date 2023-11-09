#include <stdio.h>

int main() {

    int array2D[4][4] = {8, 2, 22, 97, 49, 49, 99, 40, 81, 49, 31, 73, 52, 70, 95, 23}, size = sizeof(array2D) / sizeof(array2D[0]), major = 0, majorHor, majorVert, temp = 0, majorDP = 1, majorDS = 1;

    for(int i = 0; i < size; i++) {
        majorHor = 1;
        majorVert = 1;
        for(int j = 0; j < size; j++) {
            
            majorHor *= array2D[i][j];
            majorVert *= array2D[j][i];

            if(i == j) {
                majorDP *= array2D[i][j];
            }

            if((i + j) == (size - 1)) {
                majorDS *= array2D[i][j];
            }

        }

        if(majorHor > majorVert) {
            temp = majorHor;
        } else {
            temp = majorVert;
        }

        if(temp > major) {
            major = temp;
        }
        
    }

    if(major < majorDP) {
        major = majorDP;
    }

    if(major < majorDS) {
        major = majorDS;
    }

    printf("Major: %d\n", major);
    
    return 0;

}