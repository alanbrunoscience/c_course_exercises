#include <stdio.h>
#include <stdlib.h>

int main() {

    int *binary_number = NULL;
    int length = 0;
    int dec_num = 2;
    int remainder = 0;

    for(int i = dec_num; i > 0; i /= 2) {
        length++;
    }

    int *temp = (int *)realloc(binary_number, length * sizeof(int));

    if(temp == NULL) {
        puts("\n-> Memory (re)allocation failed.");
        free(binary_number);
        return 1;
    }

    binary_number = temp;

    for(int i = (length - 1); i >= 0; i--) {
        remainder = dec_num % 2;
        binary_number[i] = remainder;
        printf("binary_number[%d] = %d\n", i, binary_number[i]);
        dec_num /= 2;
    }

    free(binary_number);

    return 0;

}