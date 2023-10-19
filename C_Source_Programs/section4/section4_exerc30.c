#include <stdio.h>

int main(){

    int vetNum[3], minor, index = 0, temp;

    for(int i = 0; i < 3; i++) {
        printf("Enter the %dº number, please:\n", (i+1));
        scanf("%d", &vetNum[i]);
    }

    for(int i = 0; i < 3; i ++){
        minor = i;
        for(int j = minor + 1; j < 3; j++) {
            if(vetNum[j] < vetNum[minor]){
                minor = j;
            }
        }
        temp = vetNum[i];
        vetNum[i] = vetNum[minor];
        vetNum[minor] = temp;
    }

    printf("| ");

    for(int k = 0; k < 5; k++) {
        printf("%d | ", vetNum[k]);
    }

    printf("\n");

    return 0;

}