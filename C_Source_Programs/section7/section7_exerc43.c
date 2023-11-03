#include <stdio.h>

int main() {

    int twoDimArray[4][4], sizeTD = sizeof(twoDimArray) / sizeof(twoDimArray[0]), sizeOD = sizeTD * sizeTD, oneDimArray[sizeOD], count10 = 0;

    printf("Enter the elements' value to occupy the positions below:\n");
    for(int i = 0; i < sizeTD; i++) {
        for(int j = 0; j < sizeTD; j++) {
            printf("array[%d][%d]: ", i, j);
            scanf("%d", &twoDimArray[i][j]);
        }
    }

    for(int i = 0; i < sizeTD; i++) {
        for(int j = 0; j < sizeTD; j++) {
            if(twoDimArray[i][j] > 10) {
                oneDimArray[count10] = twoDimArray[i][j];
                count10++;
            }
        }
    }

    printf("\n*** ELEMENTS GREATER THAN 10 ***\n\n-> ");
    for(int i = 0; i < count10; i ++){
        printf("%d ", oneDimArray[i]);
    }
    printf("\n-> Total of numbers greater than 10: %d\n", count10);

    return 0;

}