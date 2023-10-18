#include <stdio.h>

int main() {

    int numbers[10], major = 0, posLargNum = 0;

    printf("Enter the 1º value (numbers[0]), please: ");
    scanf("%d", &numbers[0]);
    major = numbers[0];
    posLargNum = 0;

    for(int i = 1; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        printf("Enter the %dº value (numbers[%d]), please: ", (i+1), i);
        scanf("%d", &numbers[i]);

        if(major < numbers[i]){
            major = numbers[i];
            posLargNum = i;
        }
    }

    printf("\n*** ARRAY ***\n\n");
    for(int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    printf("\n*** LARGEST NUMBER ***\n\n");
    printf("The largest number is %d, and is in position numbers[%d].\n", major, posLargNum);

    return 0;

}