#include <stdio.h>

// Functions prototype
void dataInput(int size, float array2D[][size]);
void printElementsAddress(int size, float array2D[][size]);

int main() {

    float array2D[3][3];
    int size = sizeof(array2D) / sizeof(array2D[0]);

    dataInput(size, array2D);

    printElementsAddress(size, array2D);

    return 0;

}

void dataInput(int size, float array2D[][size]) {

    printf("Fill in the elements' values of the positions below:\n\n");
    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("-> array2D[%d][%d]: ", i, j);
            scanf("%f", &array2D[i][j]);
        }
    }
}

void printElementsAddress(int size, float array2D[][size]) {

    printf("\n\n*** ARRAY 2D ELEMENTS' VALUES AND THEIR ADDRESS ***\n\n");
    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("-> array2D[%d][%d]: %.2f / Address: %p\n", i, j, array2D[i][j], (void *)&array2D[i][j]);
        }        
    }

}