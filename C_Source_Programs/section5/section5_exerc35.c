#include <stdio.h>

int main() {

    int n1, n2, sumOdd = 0;

    printf("Enter the initial value and final value, please:\n");
    scanf("%d %d", &n1, &n2);

    if(n1 > n2) {
        for(int i = n2; i <= n1; i++) {
            if(i % 2 != 0){
                sumOdd += i;
            }
        }

        printf("The sum of odd numbers between %d and %d (including these numbers) is %d.\n", n2, n1, sumOdd);

    } else {
        for(int i = n1; i <= n2; i++) {
            if(i % 2 != 0){
                sumOdd += i;
            }
        }

        printf("The sum of odd numbers between %d and %d (including these numbers) is %d.\n", n1, n2, sumOdd);

    }

    return 0;

}