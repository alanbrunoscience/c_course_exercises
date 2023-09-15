#include <stdio.h>

int main() {

    printf("*** FOR ***\n-> ");

    for(int i = 1; i <= 100; i++){
        printf("%d ", i);
    }

    printf("\n\n");

    int j = 1;

    printf("*** WHILE ***\n-> ");

    while(j <= 100){
        printf("%d ", j);
        j++;
    }

    printf("\n\n");

    int k = 1;

    printf("*** DO... WHILE ***\n-> ");

    do {

        printf("%d ", k);
        k++;

    } while(k <= 100);

    printf("\n");
    
    return 0;

}