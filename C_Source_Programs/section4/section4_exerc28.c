#include <stdio.h>
#include <math.h>

int main(){

    int n1, n2, n3;

    printf("Enter the first integer number, please:\n");
    scanf("%d", &n1);

    printf("Enter the second integer number, please:\n");
    scanf("%d", &n2);

    printf("Enter the third integer number, please:\n");
    scanf("%d", &n3);

    printf("The geometric mean is %.2f.\n", (cbrt((n1 * n2 * n3))));
    printf("The weighted mean is %.2f.\n", ((n1 + 2 * n2 + 3 * n3) / 6.0));
    printf("The harmonic mean is %.2f.\n", (1.0 / (1.0/n1 + 1.0/n2 + 1.0/n3)));
    printf("The arithmetic mean is %.2f.\n", ((n1 + n2 + n3) / 3.0));

    return 0;
    
}