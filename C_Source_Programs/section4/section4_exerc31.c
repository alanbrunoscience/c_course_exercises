#include <stdio.h>
#include <math.h>

int main(){

    float height, weight, tolerance = 0.001;

    printf("Enter your height, please:\n");
    scanf("%f", &height);

    printf("Enter your weight, please:\n");
    scanf("%f", &weight);

    if(height < 1.20 && weight < 60.0) {
        printf("Your classification is A.\n");
    } else if(height < 1.20 && weight >= 60.0 && weight <= 90.0) {
        printf("Your classification is D.\n");
    } else if(height < 1.20 && weight > 90.0) {
        printf("Your classification is G.\n");
    } else if (height >= 1.20 && height <= 1.70 && weight < 60.0) {
        printf("Your classification is B.\n");
    } else if (height >= 1.20 && height <= 1.70 && weight >= 60.0 && weight <= 90.0) {
        printf("Your classification is E.\n");
    } else if ((fabs(height - 1.70) <= tolerance && fabs(weight - 91.0) <= tolerance)) {
        printf("Your classification is H.\n");
    } else if (height > 1.70 && weight < 60.0) {
        printf("Your classification is C.\n");
    } else if (height > 1.70 && weight >= 60.0 && weight <= 90.0) {
        printf("Your classification is F.\n");
    } else {
        printf("Your classification is I.\n");
    }

    return 0;

}