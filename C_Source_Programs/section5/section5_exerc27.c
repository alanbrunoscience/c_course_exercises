#include <stdio.h>

int main() {

    int num;
    float harmNum = 0;

    printf("Enter an integer number, please:\n");
    scanf("%d", &num);

    if(num == 0) {
        printf("Zero cannot be an element of a harmonic progression.\n");
    } else {
        for(int i = 1; i <= num; i++) {
            harmNum += (1/(float)i);
        }

        printf("H(%d) = 1", num);

        for(int i = 2; i <= num; i++) {
            printf(" + 1/%d", i);
        }

        printf(" = %.2f\n", harmNum);
    }

    return 0;

}