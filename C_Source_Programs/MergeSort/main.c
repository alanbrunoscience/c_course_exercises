#include "ordenacao.h"
#include <stdio.h>

int main(void) {

    int tamanho = 10;
    int v[] = {9, 4, 3, 6, 3, 2, 5, 7, 1, 8};

    for(int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");

    mergeSort(v, tamanho);

    for(int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");

    return 0;

}