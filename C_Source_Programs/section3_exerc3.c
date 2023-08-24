#include <stdio.h>

int main(){

    int num, sum = 0;

    for(int i = 0; i < 3; i++) {

        printf("Enter the %dº number:\n", (i+1));
        scanf("%d", &num);

        sum += num;

    }

    printf("The sum of numbers is %d.\n", sum);

    return 0;

}