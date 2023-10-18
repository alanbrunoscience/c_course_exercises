#include <stdio.h>
#include <math.h>

int main() {

    float numbers[10];

    for(int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        printf("Enter the %dº real value, please: ", (i+1));
        scanf("%f", &numbers[i]);
        getchar();
    }

    printf("\n*** FIRST ARRAY ***\n\n");
    for(int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        printf("numbers[%d] = %.2f\n", i, numbers[i]);
    }

    printf("\n*** SECOND ARRAY ***\n\n");
    
    for(int j = 0; j < sizeof(numbers) / sizeof(numbers[0]); j++) {
        numbers[j] = pow(numbers[j], 2);
        printf("numbers[%d]² = %.2f\n", j, numbers[j]);
    }

    return 0;

}