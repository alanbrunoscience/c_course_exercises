#include <stdio.h>

int main(){

    int number, sum = 0, arrayNum[10];

    for(int i = 0; i < 10; i++) {
        
        printf("Enter the %dº number, please:\n", (i+1));
        scanf("%d", &number);

        sum += number;
        arrayNum[i] = number;
    }

    for(int i = 0; i < 10; i++) {

        printf("%d", arrayNum[i]);

        if(i <= 8) {
            printf(" + ");
        } else {
            printf(" = ");
        }
        
    }

    printf("%d\n", sum);

    return 0;

}