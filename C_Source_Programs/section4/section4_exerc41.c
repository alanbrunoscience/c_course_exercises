#include <stdio.h>
#include <math.h>

int main() {

    float weight, height, bmi;

    printf("*** BODY MASS INDEX (BMI) ***\n");
    printf("Enter you weight (Kg), please:\n-> ");
    scanf("%f", &weight);
    printf("Enter you height (m), please:\n-> ");
    scanf("%f", &height);

    bmi = weight / pow(height, 2.0);

    if(bmi < 17.0){
        printf("Very Underweight\n");
    } else if(bmi >= 17.0 && bmi < 18.5) {
        printf("Under Weight\n");
    } else if(bmi >= 18.5 && bmi < 25.0) {
        printf("Normal Weight\n");
    } else if(bmi >= 25.0 && bmi < 30.0) {
        printf("Overweight\n");
    } else if(bmi >= 30.0 && bmi < 35.0) {
        printf("Obesity I\n");
    } else if(bmi >= 35.0 && bmi < 40.0) {
        printf("Obesity II (Severe)\n");
    } else {
        printf("Obesity III (Morbid)\n");
    }

    return 0;

}