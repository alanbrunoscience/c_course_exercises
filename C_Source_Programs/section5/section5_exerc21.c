#include <stdio.h>

int main() {

    int n1, n2, sum = 0, mult = 1;

    printf("Enter the first number, please:\n");
    scanf("%d", &n1);

    printf("Enter the second number, please:\n");
    scanf("%d", &n2);

    if(n1 > n2){
        for(int i = n1; i >= n2; i--){
            if(i % 2 == 0){
                sum += i;
            } else {
                mult *= i;
            }
        }

        printf("The sum of even numbers between %d and %d is %d.\n", n2, n1, sum);
        printf("The multiplication of odd numbers between %d and %d is %d.\n", n2, n1, mult);

    } else {
        for(int i = n1; i <= n2; i++){
            if(i % 2 == 0){
                sum += i;
            } else {
                mult *= i;
            }
        }

        printf("The sum of even numbers between %d and %d is %d.\n", n1, n2, sum);
        printf("The multiplication of odd numbers between %d and %d is %d.\n", n1, n2, mult);

    }

    return 0;

}