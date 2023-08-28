#include <stdio.h>

int main(){

    int i = 0;
    float num, sum = 0;

    while(i < 3){
        
        printf("Enter the %dº number, please:\n", (i+1));
        scanf("%f", &num);

        sum += (num * num);

        i++;

    }

    printf("The sum of all square numbers is %.2f.\n", sum);

    return 0;

}