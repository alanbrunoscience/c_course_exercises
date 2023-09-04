#include <stdio.h>

int main(){

    float height;
    char gender[6];

    printf("Enter your height, please:\n");
    scanf("%f", &height);

    printf("Enter your gender (male / female), please:\n");
    scanf("%s", gender);

    if (gender[0] == 'f' || gender[0] == 'F')
        printf("Your ideal weight is %.2f\n", ((62.1 * height) - 44.7));
    else if (gender[0] == 'm' || gender[0] == 'M')
        printf("Your ideal weight is %.2f\n", ((72.7 * height) - 58));
    else
        printf("The gender inserted is invalid!\n");

    return 0;

}