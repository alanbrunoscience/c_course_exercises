#include <stdio.h>
#include <math.h>

int main() {

    long long int sumSqr = 0, sum = 0, sqrSum;

    for(int i = 1; i <= 100; i++) {
        sumSqr += pow(i, 2);
    }

    for(int j = 1; j <= 100; j++) {
        sum += j;
    }

    sqrSum = pow(sum, 2);

    printf("%lld - %lld = %lld\n", sqrSum, sumSqr, (sqrSum - sumSqr));

    return 0;

}