#include <stdio.h>

int main(){

    float r1, r2, r;

    do {
        printf("Enter the first resistance value (R1), please:\n");
        scanf("%f", &r1);

        printf("Enter the second resistance value (R2), please:\n");
        scanf("%f", &r2);

        r = (r1 * r2)/(r1 + r2);

        if(r1 > 0 && r2 > 0){
            printf("\nThe total resistance value (R) is %.2f ohms.\n\n", r);
            printf("===========================================\n\n");
        } else {
            break;
        }
        
    } while(r1 > 0 || r2 > 0);

    printf("Finishing the program because you entered 0...\n");

    return 0;

}