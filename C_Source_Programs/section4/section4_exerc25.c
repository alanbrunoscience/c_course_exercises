#include <stdio.h>
#include <math.h>

int main (){

    float a, b, c, delta, x, x1, x2;

    printf("Enter the coefficient value 'a' from the quadratic equation, please:\n");
    scanf("%f",&a);

    printf("Enter the coefficient value 'b' from the quadratic equation, please:\n");
    scanf("%f", &b);

    printf("Enter the coefficient value 'c' from the quadratic equation, please:\n");
    scanf("%f", &c);

    while(a == 0){

        printf("The coefficient 'a' must be different from zero. Otherwise, this is not a quadratic equation. So enter the coefficient value 'a' again:\n");
        scanf("%f",&a);

    }

    delta = pow(b, 2.0) - 4.0 * a * c;

    if(delta < 0.0) {

        printf("There is no root for this quadratic equation.\n");

    } else if (delta == 0.0) {

        x = ((-1) * b) / (2 * a);

        printf("This quadratic equation has a single root, which the value is %.f.\n", x);

    } else {

        x1 = (((-1) * b) + sqrt(delta)) / (2 * a);

        x2 = (((-1) * b) - sqrt(delta)) / (2 * a);

        printf("The roots of this quadratic equation are:\n-> x1 = %.2f;\n-> x2 = %.2f;\n", x1, x2);
        
    }

    return 0;

}