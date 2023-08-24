#include <stdio.h>

int main(){

    int num, sum = 0;

    for(int i = 0; i < 3; i++) {

        printf("Enter the %dº value, please:\n", (i+1));

        scanf("%d", &num);

        sum += num;

    }

    printf("The sum of values is %d.\n", sum);

}