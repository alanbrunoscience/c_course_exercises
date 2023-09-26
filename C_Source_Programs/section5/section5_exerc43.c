#include <stdio.h>

int main () {

    int age, count = 1, sumAges = 0;
    float average;

    do {

        printf("Enter the age, please:\n");
        scanf("%d", &age);

        if(age <= 0){
            break;
        } else {
            sumAges += age;
            average = (float) sumAges / (float) count;
            count++;
        }

    } while(age > 0);

    printf("The average age is %.2f.\n", average);

    return 0;

}
