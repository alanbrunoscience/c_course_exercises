#include <stdio.h>

int main() {

    float n1, n2;

    printf("Enter the first number, please:\n");
    scanf("%f", &n1);

    printf("Enter the second number, please:\n");
    scanf("%f", &n2);

    if(n1 > n2){
        printf("The biggest number is %.2f\n", n1);
    } else {
        printf("The biggest number is %.2f\n", n2);
    }

    return 0;

}