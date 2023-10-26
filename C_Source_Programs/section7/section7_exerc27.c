#include <stdio.h>

int main() {

    int arrayNum[100], size = sizeof(arrayNum) / sizeof(arrayNum[0]), j = 0;

    for(int i = 0; i < size; i++) {
        while(j % 7 == 0 || j % 10 == 7) {
            j++;
        }
        arrayNum[i] = j;
        j++;
    }

    for (int i = 0; i < size; i++) {
        printf("arrayNum[%d]: %d\n", i, arrayNum[i]);
    }

    return 0;

}