#include <stdio.h>

int main() {

    float number, arrayNum[10];

    for(int i = 0; i < 10; i++) {
            
        printf("Enter the %dº number, please:\n", (i+1));
        scanf("%f", &arrayNum[i]);
    
    }

    float major = arrayNum[0], minor = arrayNum[0];

    for(int i = 0; i < 10; i++) {

        if(major < arrayNum[i]) {
            major = arrayNum[i];
        }

        if(minor > arrayNum[i]) {
            minor = arrayNum[i];
        }

    }

    printf("The largest number is %.2f and the smallest number is %.2f.\n", major, minor);

    return 0;

}