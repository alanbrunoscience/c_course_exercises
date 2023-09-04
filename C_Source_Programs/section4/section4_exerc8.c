#include <stdio.h>

int main(){

    float n1, n2, average;

    do {
        
        printf("Enter the first grade, please:\n");
        scanf("%f", &n1);

        printf("Enter the second grade, please:\n");
        scanf("%f", &n2);

        if(n1 < 0.0 || n1 > 10.0 || n2 < 0.0 || n2 > 10.0){
            printf("\n*** The grades are invalid! They need to be greater or equal to 0.00 and smaller or equal to 10.00. ***\n\n");
        }

    } while(n1 < 0.0 || n1 > 10.0 || n2 < 0.0 || n2 > 10.0);

    average = (n1 + n2) / 2;

    printf("The average is %.2f.\n", average);

    return 0;

}