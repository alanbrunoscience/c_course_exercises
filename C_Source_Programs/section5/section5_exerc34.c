#include <stdio.h>

int main() {

    int i, dividers;
    long long int number = 18;

    do {
        dividers = 0;
        number += 2;
        for(i = 1; i <= 20; i++) {
            if(number % i == 0){
                dividers++;
            }
        }
    } while(dividers != 20);

    printf("The smallest number evenly divisible by all numbers from 1 to 20 is: %lld\n", number);

    // Another form to do this exercise
    // int countDivisors = 0;
    // long long int number;
 
    // for(number = 18; countDivisors < 20; number+=2) {
    //     countDivisors = 0;
    //     for(int i = 1; i <= 20; i++) {
    //         if(number % i == 0) {
    //             countDivisors++;
    //         }
    //     }
    // }
    

    // printf("The smallest number evenly divisible by all numbers from 1 to 20 is: %lld\n", (number - 2));

    return 0;

}