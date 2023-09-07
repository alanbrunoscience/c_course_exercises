#include <stdio.h>

int main(){

    int age;

    printf("Enter the age, please:\n");
    scanf("%d", &age);

    if(age >= 5 && age <= 7){
        printf("Infant A.\n");
    } else if(age >= 8 && age <= 10){
        printf("Infant B.\n");
    } else if(age >= 11 && age <= 13){
        printf("Juvenile A.\n");
    } else if(age >= 14 && age <= 17) {
        printf("Juvenile B.\n");
    } else {
        printf("Senior.\n");
    }

    return 0;

}