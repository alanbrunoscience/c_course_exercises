#include <stdio.h>

int main() {

    int sum = 0, fib = 0, temp1 = 1, temp2 = 1;

    do {
        temp1 = fib;
        fib += temp2;
        temp2 = temp1;

        if(fib % 2 == 0) {
            
            if(sum <= 4000000) {
                sum += fib;
            }
        }

    } while(sum <= 4000000);

    printf("The sum of all even values of the Fibonacci sequence in which the sum doesn't over 4000000 is %d.\n", (sum - fib));

    return 0;

}