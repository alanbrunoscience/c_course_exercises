#include <stdio.h>

int main(){

    int num;

    do{

        printf("Enter an integer number greater than 0, please:\n");
        scanf("%d", &num);

        if(num < 1){
            printf("\n*** This is not a valid number. The number needs to be greater than 0. Enter a new number again ***\n\n");
        }

    } while(num < 1);

    printf("D(%d) = {", num);

    for(int i = 1; i <= num; i++) {
        if(num % i == 0) {

            if(i == num){
                printf("%d", i);
            } else {
                printf("%d, ", i);
            }

        }
    }

    printf("}\n");

    return 0;

}