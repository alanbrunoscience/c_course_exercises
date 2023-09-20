#include <stdio.h>

int main() {

    int fat;
    float e = 0;

    printf("S = 0");

    for(int i = 1; i < 10; i++) {

        fat = 1;

        if(i % 2 == 0) {
            for(int j = i; j > 0; j--) {
                fat *= j;
            }
            e += (1/(float)fat);
            printf(" + 1/%d", fat);
        }
    }
    printf(" = %.2f\n", e);

    return 0;

}