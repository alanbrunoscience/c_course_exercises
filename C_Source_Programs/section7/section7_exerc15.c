#include <stdio.h>

int main() {
    int arrayNum[20], newArray[20], i, minor, temp, count = 0;

    for(i = 0; i < 20; i++) {
        printf("Enter the %dº number, please: ", (i+1));
        scanf("%d", &arrayNum[i]);
    }

    for(i = 0; i < 20; i++) {
        minor = i;
        for(int j = i + 1; j < 20; j++) {
            if(arrayNum[j] < arrayNum[minor]) {
                minor = j;
            }
        }
        temp = arrayNum[i];
        arrayNum[i] = arrayNum[minor];
        arrayNum[minor] = temp;
    }

    for(i = 0; i < 20; i++) {
        if(arrayNum[i] != arrayNum[i+1]) {
            newArray[count] = arrayNum[i];
            count++;
        }
    }

    printf("\n*** NEW ARRAY ***\n\n");
    for(i = 0; i < count; i++) {
        printf("newArray[%d] = %d\n", i, newArray[i]);
    }

    return 0;
}
