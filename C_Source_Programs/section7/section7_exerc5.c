#include <stdio.h>

int main() {

    int numbers[10], evenNumbers[10], sumNum = 0, count = 0;

    for(int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        printf("Enter the %dº value (numbers[%d]), please: ", (i+1), i);
        scanf("%d", &numbers[i]);
        getchar();

        if(numbers[i] % 2 == 0) {
            evenNumbers[count] = numbers[i];
            sumNum += evenNumbers[count];
            count++;
        }
    }

    printf("\n\n");

    printf("*** EVEN NUMBERS ***\n");

    for(int j = 0; j < count; j++) {
        printf("%d\n", evenNumbers[j]);
    }

    printf("\n");

    printf("The sum of all even numbers is %d\n", sumNum);

    return 0;

}