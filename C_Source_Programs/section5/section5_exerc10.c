#include <stdio.h>

int main() {

    int sum = 0;

    for(int i = 0; i <= 50; i++) {
        
        if(i % 2 == 0) {
            printf("%d", i);
            sum += i;

            if(i < 50) {
                printf(" + ");
            } else {
                printf(" = ");
            }
        }
    }

    printf("%d\n", sum);

    return 0;

}