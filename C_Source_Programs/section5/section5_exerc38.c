#include <stdio.h>
#include <math.h>

int main() {

    int c, n = 1, sum = 0;

    for(int a = 1; a <= 500; a++) {
        for(int b = a; b <= 500; b++) {
            c = 1000 - a - b;
            if(pow(a, 2) + pow(b, 2) == pow(c, 2)) {
                sum = a + b + c;
                printf("*** RESULT ***\n\n");
                printf("-> A = %d\n", a);
                printf("-> B = %d\n", b);
                printf("-> C = %d\n\n", c);
                printf("%d + %d + %d = %d\n", a, b, c, sum);
                printf("\n*** REAL PROOF ***\n\n");
                printf("%d² = %d² + %d²\n", c, a, b);
                printf("%.0f = %.0f + %.0f\n", pow(c, 2), pow(a, 2), pow(b, 2));
                printf("%.0f = %.0f\n", pow(c, 2), (pow(a, 2) + pow(b, 2)));
            }
        }
    }

    return 0;

}