#include <stdio.h>

int main() {

    float arrayA[5], arrayB[5], size = sizeof(arrayA) / sizeof(arrayA[0]), dotProd = 0;

    printf("*** ARRAY A ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("Enter the %dº number, please: ", (i+1));
        scanf("%f", &arrayA[i]);
    }

    printf("\n*** ARRAY B ***\n\n");
    for(int i = 0; i < size; i++) {
        printf("Enter the %dº number, please: ", (i+1));
        scanf("%f", &arrayB[i]);
    }

    for (int i = 0; i < size; i++) {
        if(i != (size - 1)) {
            printf("%.2f * %.2f + ", arrayA[i], arrayB[i]);
            dotProd += (arrayA[i] * arrayB[i]);
        } else {
            printf("%.2f * %.2f = ", arrayA[i], arrayB[i]);
            dotProd += (arrayA[i] * arrayB[i]);
        }
    }

    printf("%.2f\n", dotProd);
    
    return 0;

}