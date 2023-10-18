#include <stdio.h>

int main() {

    int numbers[10], major = 0, minor = 0;

    printf("Enter the 1º value (numbers[0]), please: ");
    scanf("%d", &numbers[0]);
    getchar();
    major = numbers[0];
    minor = numbers[0];

    for(int i = 1; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        printf("Enter the %dº value (numbers[%d]), please: ", (i+1), i);
        scanf("%d", &numbers[i]);
        getchar();

        if(major < numbers[i]){
            major = numbers[i];
        }

        if(minor > numbers[i]) {
            minor = numbers[i];
        }
    }

    printf("\nThe biggest number is %d;\n", major);
    printf("The smallest number is %d.\n", minor);

    return 0;

}