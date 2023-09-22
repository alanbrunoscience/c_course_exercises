#include <stdio.h>

int main() {

    int n, i, j, index = 0, temp = 0;
    
    
    printf("Enter the first integer number (n), please:\n");
    scanf("%d", &n);
    
    printf("Enter the second integer number (i), please:\n");
    scanf("%d", &i);
    
    printf("Enter the third integer number (j), please:\n");
    scanf("%d", &j);

    int arrayNum[n];

    while(index < n) {

        if(temp % i == 0 || temp % j == 0) {
            arrayNum[index] = temp;
            index++;
            temp++;
        } else {
            temp++;
        }
    }

    size_t size = sizeof(arrayNum) / sizeof(arrayNum[0]);

    for(int k = 0; k < size; k++) {
        if(k == size - 1) {
            printf("%d.", arrayNum[k]);
        } else {
            printf("%d, ", arrayNum[k]);
        }
        
    }

    printf("\n");

    return 0;

}