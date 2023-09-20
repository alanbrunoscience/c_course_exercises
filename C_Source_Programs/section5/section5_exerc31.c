#include <stdio.h>

int main() {
    int num[50];
    float sum = 1;

    printf("S = 1/1");

    for (int i = 2; i <= 100; i++) {
        if (i % 2 != 0) {
            num[i / 2] = i;
        }
    }

    for (int i = 1; i < sizeof(num) / sizeof(num[0]); i++) {
        printf(" + %d/%d", num[i], i+1);
        sum += ((float)(num[i]) / (float)(i+1));
    }

    printf(" = %.2f\n", sum);

    return 0;
}