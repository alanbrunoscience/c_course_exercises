#include <stdio.h>

/* The algorithm used to sort the array was the Quicksort. */

// Functions prototype
void data_input(int *arrayNum, int size);
int data_validation(int *arrayNum, int size);
int partition(int *arrayNum, int start, int end);
void quicksort(int *arrayNum, int start, int end);
void sorted_array_output(int *arrayNum, int size);

int main() {

    int arrayNum[10], size = sizeof(arrayNum) / sizeof(arrayNum[0]);

    data_input(arrayNum, size);

    int return_array = data_validation(arrayNum, size);

    if(return_array == 0) {
        quicksort(arrayNum, 0, size - 1);
        sorted_array_output(arrayNum, size);
    } else {
        printf("\n-> There are nothing to sort, once all the elements' values are equal.\n");
    }

    return 0;

}

// Functions

void data_input(int *arrayNum, int size) {
    printf("*** DATA INPUT ***\n\n");
    printf("Fill in the values of the elements in the positions below:\n\n");
    for(int i = 0; i < size; i++) {
        printf("-> arrayNum[%d]: ", i);
        scanf("%d", &arrayNum[i]);
    }
}

int data_validation(int *arrayNum, int size) {

    int countDif = 0;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j <= i; j++) {
            if(arrayNum[j] != arrayNum[i]) {
                countDif++;
                return 0;
            }
        }
    }

    if(countDif == 0) {
        return 1;
    }

}

int partition(int *arrayNum, int start, int end) {
    
    int pivot = arrayNum[end];
    int pIndex = start;
    
    for(int i = start; i < end; i++) {
        if(arrayNum[i] <= pivot) {
            // Replace arrayNum[pIndex] with arrayNum[i]
            int temp = arrayNum[pIndex];
            arrayNum[pIndex] = arrayNum[i];
            arrayNum[i] = temp;
            pIndex++;
        }
    }

    int temp = arrayNum[pIndex];
    arrayNum[pIndex] = pivot;
    arrayNum[end] = temp;

    return pIndex;

}

void quicksort(int *arrayNum, int start, int end) {
    if(end > start) {
        int indexPivot = partition(arrayNum, start, end);
        quicksort(arrayNum, start, indexPivot - 1);
        quicksort(arrayNum, indexPivot + 1, end);
    }
}

void sorted_array_output(int *arrayNum, int size) {
    printf("\n*** SORTED ARRAY ***\n\n-> ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arrayNum[i]);
    }
    printf("\n");
}