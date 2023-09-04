#include <stdio.h>

int main(){

    int n1, n2;

    printf("Enter the first number, please:\n");
    scanf("%d", &n1);
    
    printf("Enter the second number, please:\n");
    scanf("%d", &n2);

    if(n1 > n2)
        printf("The biggest number is %d.\n", n1);
    else if (n2 > n1)
        printf("The biggest number is %d.\n", n2);
    else
        printf("Equal numbers!\n");

    return 0;

}



