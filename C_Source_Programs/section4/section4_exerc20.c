#include <stdio.h>

int main(){

    float a, b, c;

    printf("Enter the first value, please:\n");
    scanf("%f", &a);

    printf("Enter the second value, please:\n");
    scanf("%f", &b);

    printf("Enter the third value, please:\n");
    scanf("%f", &c);

    if (a < (b + c) && b < (a + c) && c < (a + b)){
        if(a == b && b == c) {
            printf("This is an equilateral triangle.\n");
        } else if (a == b && a != c || a == c && a != b || b == c && b != a) {
            printf("This is an isosceles triangle.\n");
        } else {
            printf("This is a scalene triangle.\n");
        }
        
    } else {
        printf("*** These values can't form a triangle, because the length of each side of a triangle must be more minor than the sum of from the other two sides. ***\n");
    }

    return 0;

}