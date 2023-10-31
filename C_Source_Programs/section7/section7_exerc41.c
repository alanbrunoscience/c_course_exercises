#include <stdio.h>

int main() {

    int n;

    printf("Enter an integer number, please:\n");
    scanf("%d", &n);

    int arrayA[n], arrayB[n];

    for(int i = 0; i < n; i++){
        arrayA[i] = 0;
		arrayB[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) {
                arrayA[j] = 1;
                printf("%d ", arrayA[j]);
            } else {
                arrayA[j] = arrayB[j] + arrayB[j - 1];
                printf("%d ", arrayA[j]);
            }
        }
        for(int k = 0; k <= i; k++) {
			arrayB[k] = arrayA[k];
        }
        printf("\n");
    }

    return 0;

}