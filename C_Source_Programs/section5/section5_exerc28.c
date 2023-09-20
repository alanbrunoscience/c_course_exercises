#include <stdio.h>

int main() {

    int num, fat;
    float e = 1;

    printf("Enter an integer number greater than 0, please:\n");
    scanf("%d", &num);

    if(num <= 0) {
        printf("The number is invalid. It needs to be greater than zero.\n");
    } else {
        printf("E = 1");

        for(int i = 1; i <= num; i++) {
            fat = 1;
            for(int j = i; j > 0; j--) {
                fat *= j;
            }
            e += (1/(float)fat);
            printf(" + 1/%d", fat);
        }
        printf(" = %.2f\n", e);
    }

    return 0;

}