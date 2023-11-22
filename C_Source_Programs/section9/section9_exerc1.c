#include <stdio.h>

// Functions prototype
void dataInput(int arrayNum[], int size);
void biggestValue(int arrayNum[], int size);

int main() {

    int arrayNum[10], size = sizeof(arrayNum) / sizeof(arrayNum[0]);

    dataInput(arrayNum, size);

    biggestValue(arrayNum, size);

    return 0;

}

void dataInput(int arrayNum[], int size) {

    printf("Fill in the values of the positions below:\n\n");
    for(int i = 0; i < size; i++) {
        printf("arrayNum[%d]: ", i);
        scanf("%d", &arrayNum[i]);
    }

}

void biggestValue(int arrayNum[], int size) {

    int major = arrayNum[0];

    printf("\n*** THE LARGEST VALUE IN THE ARRAY ***\n\n");
    for(int i = 0; i < size; i++) {
        if(major < arrayNum[i]) {
            major = arrayNum[i];
        }
    }

    printf("-> %d\n", major);

}