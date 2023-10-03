#include <stdio.h>

int main() {

    #include <stdio.h>
#include <stdbool.h>

int main() {
    int num = 2000000;
    long long sumPrime = 0;

    // Create a boolean array "prime[0:num]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[num+1];
    for (int i = 0; i <= num; i++) {
        prime[i] = true;
    }

    // Apply the Sieve of Eratosthenes algorithm to find all prime numbers
    for (int p = 2; p * p <= num; p++) {
        if (prime[p] == true) {
            // Update all multiples of p as not prime
            for (int i = p * p; i <= num; i += p) {
                prime[i] = false;
            }
        }
    }

    // Calculate the sum of all prime numbers
    for (int p = 2; p <= num; p++) {
        if (prime[p]) {
            sumPrime += p;
        }
    }

    printf("The sum of all prime numbers smaller than %d is %lld.\n", num, sumPrime);

    return 0;
}

    // int countDiv = 0, sumPrime = 2, num = 200000;

    // for(int i = 3; i < num; i += 2) {
    //     for(int j = 1; j <= i; j++) {
    //         if(i % j == 0) {
    //             countDiv++;
    //         }
    //     }

    //     if(countDiv == 2) {
    //         sumPrime += i;
    //     }

    //     countDiv = 0;

    // }

    // printf("The sum of all prime numbers smaller than %d is %d.\n", num, sumPrime);

    // return 0;