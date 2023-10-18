#include <stdio.h>

int main() {

    int numbers[8], n1, n2, sum = 0;

    for(int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        printf("Enter the %dº value (numbers[%d]), please: ", (i+1), i);
        scanf("%d", &numbers[i]);
    }

    printf("\nEnter the value of X and Y between 0 and 7, please:\n");
    scanf("%d", &n1);
    scanf("%d", &n2);

    while(n1 < 0 || n2 < 0 || n1 > 7 || n2 > 7) {
        printf("\nThe numbers are invalid. Enter the value of X and Y between 0 and 7, again:\n");
        scanf("%d", &n1);
        scanf("%d", &n2);
    }

    if(n1 < n2) {
        
        for(int j = n1; j <= n2; j++) {
            sum += numbers[j];
        }

        printf("The sum of values between numbers[%d] and numbers[%d] (including) is %d.\n", n1, n2, sum);

    } else {

        for(int j = n2; j <= n1; j++) {
            sum += numbers[j];
        }

        printf("The sum of values between numbers[%d] and numbers[%d] (including) is %d.\n", n2, n1, sum);

    }

    return 0;

}