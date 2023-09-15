#include <stdio.h>

int main() {

    int num;

    printf("Enter an integer number, please:\n");
    scanf("%d", &num);

    for(int i = 1; i <= num; i++) {
        
        if(i % 2 != 0) {
            printf("%d ", i);
        }

    }

    printf("\n");

    return 0;

}